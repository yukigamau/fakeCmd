#include "const.h"
#include "ini_save.h"
#include "Sql.h"
#include "tip.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileInfo>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTimer>
#include <QToolTip>
#include <string>
#include <vector>

using std::pair, std::string, std::stringstream, std::vector;

/* 自动管理数据库连接 */

class DB
{
public:
    QSqlDatabase db;

private:
    QString addr;

public:
    DB(const QString& addr);
    ~DB();
};

DB::DB(const QString& addr):addr(addr)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(addr);
    if (!db.open())
        QMessageBox::warning(nullptr, errorTitle, db.lastError().text());
}

DB::~DB()
{
    db.close();
}

/* */

// 创建存储数据用的数据库
void createStoreDB()
{
    class DB db(STORE_DB);

    QSqlQuery query(db.db);
    if (!query.exec("CREATE TABLE IF NOT EXISTS store ("
                    "name TEXT PRIMARY KEY,"
                    "info TEXT)"))
        QMessageBox::warning(nullptr, errorTitle, query.lastError().text()+"\n创建存储失败。");
}

void readStoreDB(map<QString, QString>& read)
{
    class DB db(STORE_DB);

    QSqlQuery query(db.db);
    for(auto& [name, data]:read)
    {
        if(!query.prepare("SELECT info FROM store WHERE name = ?;"))
        {
            QMessageBox::warning(nullptr, errorTitle, query.lastError().text()+"\n存储读取语句错误");
            return;
        }

        query.addBindValue(name);
        if(!query.exec())
        {
            QMessageBox::warning(nullptr, errorTitle, query.lastError().text()+"\n读取存储失败");
            return;
        }
        query.next();
        data = query.value(0).toString();
    }
}

void updateStoreDB(vector<pair<QString, QString>>& data)
{
    class DB db(STORE_DB);
    QSqlQuery query(db.db);
    for(auto& [name, info]:data)
    {
        if(!query.prepare("INSERT INTO store (name, info)"
                           "VALUES (?, ?)"
                           "ON CONFLICT(name) DO UPDATE SET info=excluded.info;"))
        {
            QMessageBox::warning(nullptr, errorTitle, query.lastQuery() + "\n" + query.lastError().text());
            return;
        }
        query.bindValue(0, name);
        query.bindValue(1, info);
        if(!query.exec())
            QMessageBox::warning(nullptr, errorTitle, query.lastError().text());       
    }
}

/* */

/* 用于DBFileChangePage */

void delDB(QComboBox* ccb, const QStringList& name, QWidget* w)
{
    // 用于告知用户删除的信息
    QString text;

    for(const QString& s: name)
    {
        if(!QFile::exists(s))
            text += "文件" + s + "不存在。" + "\n";

        QFile::remove(s);
        text += "文件" + s + "删除成功。" + "\n";
        int index = ccb->findText(s);
        ccb->removeItem(index);
    }

    tip(w, text);
}

bool ifHad(const QString& name, Ui::MainWindow* ui)
{
    int idx=ui->dbFilesChangeCCB->findText(name);
    if(idx==-1)
        return false;
    else
        return true;
}

void newDB(const QString& name, _Out_ Ui::MainWindow* ui)
{
    if(name.isEmpty())
    {
        QMessageBox::warning(nullptr, errorTitle, "你未输入任何名字。");
        return;
    }
    class DB db(name);

    QString text;

    if(ifHad(name,ui))
        text+=name+"已经存在。";
    else
    {
        // 在dbFilesChangeCCB中插入新的项目并排序
        ui->dbFilesChangeCCB->setInsertPolicy(QComboBox::InsertAlphabetically);
        ui->dbFilesChangeCCB->addItem(name);
        text = "创建 " + name + " 成功";
    }

    tip(ui->centralwidget, text);
}

bool removeDB(const QString& old, const QString& cur, QWidget* w)
{
    if(QFile::copy(old, cur) &&
        QFile::remove(old))
    {
        const QString text = "从" + old + "移动到" + cur + "成功。";
        tip(w, text);
        return true;
    }
    else
    {
        QMessageBox::warning(nullptr, errorTitle, "从" + old + "移动到" + cur + "失败。");
        return false;
    }
}

// 重命名
bool renDB(const QString& old, _Out_ QString& cur, bool ifSaveAddr, QWidget* w)
{
    if(!QFile::exists(old))
    {
        QMessageBox::warning(nullptr, errorTitle, old+"不存在。");
        return false;
    }

    if(ifSaveAddr)
    {
       QFileInfo fi(old);
       QString dir = fi.absolutePath(); // 文件所在目录
       cur = dir + "/" + cur;  // 新文件路径
    }
    else
    {
        // 判断是否要跨盘符

        // 先创建目标路径文件
        QFile f(cur);
        if(!f.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QMessageBox::warning(nullptr, errorTitle, cur + "不是一个正确的路径。");
            return false;
        }
        f.close();
        // 删除用来检查的文件
        QFile::remove(cur);

        QFileInfo fi(cur);
        QString dir = fi.absoluteFilePath();

        if(dir.at(0) != old.at(0))  // 盘符不同转为使用移动
            return removeDB(old, cur, w);
    }

    // 确保路径统一
    changeSlash(cur);

    if(!QFile::rename(old, cur))
    {
        QMessageBox::warning(nullptr, errorTitle, "从" + old + "改变为" + cur + "失败。");
        return false;
    }
    else
    {
        const QString text = "从" + old + "改变为" + cur + "成功。";
        tip(w, text);
        return true;
    }
}

/* */

// 用于读取QComboBox与输出到QListWidget

bool ifConnected = false;
void makeCCBChecks(QComboBox* ccb, QListWidget* ls)
{
    // 清空防止重复
    ls->clear();

    for(int i = 0; i < ccb->count(); ++i)
    {
        // 读取文本
        QString s = ccb->itemText(i);
        // 包装制作QCheckBox
        QCheckBox* c = new QCheckBox(s, ls);
        QListWidgetItem *item = new QListWidgetItem(ls);
        ls->addItem(item);
        ls->setItemWidget(item, c);
        item->setSizeHint(c->sizeHint());
    }

    // 设置一行都可以点击
    if(!ifConnected)
    {
        MainWindow::connect(
            ls, &QListWidget::itemClicked, ls, [=](QListWidgetItem* item)
            {
                if (auto* cb = qobject_cast<QCheckBox*>(ls->itemWidget(item)))
                    cb->toggle();  // 切换选中状态
            });

        ifConnected = true;
    }
}

/* */

