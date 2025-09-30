#include "const.h"
#include "delegate.h"
#include "error.h"
#include "ini_save.h"
#include "mainwindow.h"
#include "sql.h"
#include "vscode.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <functional>
#include <string>
#include <QDesktopServices>
#include <QMenu>
#include <QMessageBox>
#include <QKeyEvent>
#include <QScreen>
#include <QShortcut>
#include <QTimer>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QTextEdit>
#include <QUrl>
#include <thread>

using std::function, std::ifstream, std::ofstream, std::string, std::stringstream;
using std::thread;
using std::getline, std::stoi;

/* 构造MainWindow */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 读取存储文件和修改样式
    ini(ui);

    // 安装事件过滤器
    ui->newDBNameText->installEventFilter(this);
    ui->renameText->installEventFilter(this);
    ui->tableNameText->installEventFilter(this);
    ui->folderAddText->installEventFilter(this);

    // 安装代理
    MyDelegate* delegate = new MyDelegate(ui->dbTable);
    ui->dbTable->setItemDelegate(delegate);

    // tableview右键菜单
    ui->dbTable->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->dbTable, &QTableView::customContextMenuRequested,
            this, &MainWindow::onDBTableContextMenu);
}

/* */

/* 析构MainWindow */

MainWindow::~MainWindow()
{
    save(ui);
    delete ui;
}

/* */

/* 选择页面 */

void MainWindow::on_schoolPageButton_toggled()
{
    ui->mainShowWidget->setCurrentWidget(ui->schoolPage);
}

void MainWindow::on_sqlitePageButton_toggled()
{
    ui->mainShowWidget->setCurrentWidget(ui->sqlitePage);
}

void MainWindow::on_vscodePageButton_toggled()
{
    ui->mainShowWidget->setCurrentWidget(ui->vscodePage);
}

/* */

/* 校园网服务 */

void shutdown(Ui::MainWindow* ui)
{
    if(ui->shutdownBox->isChecked())
        QApplication::quit();

}

void open(QString& qs, Ui::MainWindow* ui)
{
    if(!QDesktopServices::openUrl(QUrl(qs)))
        QMessageBox::warning(nullptr, errorTitle, "打开网页" + qs + "失败。");
    else
        shutdown(ui);
}

void MainWindow::on_chooseClassButton_clicked()
{
    QString qs = ui->chooseClassText->displayText();
    open(qs, ui);
}

void MainWindow::on_documentButton_clicked()
{
    QString qs = ui->documentText->displayText();
    open(qs, ui);
}

void MainWindow::on_hallButton_clicked()
{
    QString qs=ui->hallText->displayText();
    open(qs, ui);
}

void MainWindow::on_websiteButton_clicked()
{
    QString qs = ui->websiteText->displayText();
    open(qs, ui);
}

/* */

/* Sqlite3 */

bool askYesDel(QWidget* parent, const QStringList& sl)
{
    QString text;
    for(const QString& qs:sl)
        text += qs + "\n";

    auto reply = QMessageBox::question(
        parent,
        "确认",
        "确认删除这些项目吗——\n" + text,
        QMessageBox::Yes | QMessageBox::No,   // 设置按钮
        QMessageBox::No                       // 默认按钮
        );

    return reply == QMessageBox::Yes; // 返回 true 表示选择了“是”
}

// 返回选中的文本列表
QStringList getCheckedItems(QListWidget* list)
{
    QStringList checkedItems;

    for (int i = 0; i < list->count(); ++i)
    {
        QListWidgetItem* item = list->item(i);
        if (auto* cb = qobject_cast<QCheckBox*>(list->itemWidget(item)))
            if (cb->isChecked())
                checkedItems.append(cb->text());
    }

    return checkedItems;
}

void MainWindow::on_backButton_clicked()
{
    ui->mainShowWidget->setCurrentWidget(ui->sqlitePage);
}

void MainWindow::on_dbFilesChangeButton_clicked()
{
    ui->mainShowWidget->setCurrentWidget(ui->dbFilesChangePage);
}

void MainWindow::on_openSqlViewButton_clicked()
{
    QString dbName=ui->dbFilesChangeCCB->currentText();
    if(dbName.isEmpty())
    {
        QMessageBox::warning(ui->centralwidget, errorTitle, "尚未选择数据库，请修改数据库名单。");
        return;
    }

    QString tableName=ui->tableNameText->displayText();
    if(tableName.isEmpty())
    {
        QMessageBox::warning(ui->centralwidget, errorTitle, "尚未选择表格。");
        return;
    }

    // 打开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);   // SQLite 数据库文件路径

    // 设置表格视图model
    model = new QSqlTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit); // 自动写回容易出问题
    model->setTable(tableName);
    model->select();

    // 用 PRAGMA 获取列名和类型，设置到表头
    QSqlQuery pragma("PRAGMA table_info(" + tableName + ")", db);
    while (pragma.next())
    {
        int cid        = pragma.value(0).toInt();    // 列序号
        QString name   = pragma.value(1).toString(); // 列名
        QString type   = pragma.value(2).toString(); // 列类型
        model->setHeaderData(cid, Qt::Horizontal, type + " " + name);
    }

    QTableView *view = ui->dbTable;
    view->setModel(model);
    view->show();
}

void MainWindow::on_operateButton_clicked()
{
    // 用于sqlite3页面的处理
    enum OperateType
    {
        New,
        Del,
        Ren
    };

    OperateType operate = (OperateType)ui->operateCCB->currentIndex();
    switch(operate)
    {
    case New:
        newDB(ui->newDBNameText->displayText(), ui);
        break;

    case Del:
    {
        QStringList sl = getCheckedItems(ui->DBList);
        if(sl.isEmpty())
        {
            QMessageBox::warning(ui->centralwidget, errorTitle, "你未选择任何数据库。");
            return;
        }
        if(askYesDel(ui->centralwidget, sl))
        {
            delDB(ui->dbFilesChangeCCB, sl, ui->centralwidget);
            // 重新加载
            on_operateCCB_currentIndexChanged();
        }
    }
    break;

    case Ren:
    {
        const QString old = ui->renameCCB->currentText();
        QString cur = ui->renameText->displayText();
        if(!renDB(old, cur, ui->addrSaveButton->isChecked(), ui->centralwidget))
            return;

        // 同步修改到dbFilesChangeCCB
        int index = ui->dbFilesChangeCCB->findText(old);
        ui->dbFilesChangeCCB->setItemText(index, cur);

        // 排序数据库名单
        on_sortCCBButton_clicked();

        // 重新加载renamePage
        ui->renameCCB->clear();
        on_operateCCB_currentIndexChanged();
        ui->renameCCB->setCurrentText(cur);
    }
        break;
    }
}

void MainWindow::on_operateCCB_currentIndexChanged()
{
    int operate = ui->operateCCB->currentIndex();
    ui->operatorPage->setCurrentIndex(operate);

    switch(operate)
    {
    case 1: // deletePage
        makeCCBChecks(ui->dbFilesChangeCCB, ui->DBList);
        break;

    case 2: // renamePage
    {
        QStringList sl; // 是字母L的小写不是数字1
        for(int i = 0; i < ui->dbFilesChangeCCB->count(); ++i)
            sl << ui->dbFilesChangeCCB->itemText(i);

        ui->renameCCB->addItems(sl);
    }
        break;
    }
}

void MainWindow::on_runSqlButton_clicked()
{
    QString dbName=ui->dbFilesChangeCCB->currentText();
    if(dbName.isEmpty())
    {
        QMessageBox::warning(ui->centralwidget, errorTitle, "尚未选择数据库，请修改数据库名单。");
        return;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if(!db.open())
    {
        QMessageBox::warning(ui->centralwidget, errorTitle, "不存在选择的数据库文件。");
        return;
    }

    QString runSql=ui->runSqlText->toPlainText();
    if(runSql.isEmpty())
    {
        QMessageBox::warning(ui->centralwidget, errorTitle, "未填充运行的代码。");
        return;
    }

    QSqlQuery query;
    QString text = "运行";   // 用于提示用户处理结果
    stringstream ss(runSql.toStdString());
    string s;
    while(getline(ss, s, ';'))
    {
        bool result = query.exec(QString::fromUtf8(s));
        if(result)
            text += s + "\n";
        else
        {
            text += "\n成功。\n";
            text += query.lastQuery() + "——\n";
            text += query.lastError().text();
            QMessageBox::warning(ui->centralwidget,"操作失败原因", text);
            return;
        }
    }
    // 全部成功提示
    text += "成功。";
    tip(ui->centralwidget, text);

}

void MainWindow::on_saveButton_clicked()
{
    if(!model->submitAll())
        QMessageBox::warning(ui->centralwidget, errorTitle, model->lastError().text());
    else
        tip(ui->centralwidget, "保存成功。");
}

void MainWindow::on_sortCCBButton_clicked()
{
    auto& c = ui->dbFilesChangeCCB;

    // 记录数据方便排序结束重新确定选中项
    QString currentT = c->currentText();

    QStringList items;
    for (int i = 0; i < c->count(); ++i)
        items << c->itemText(i);

    // 排序
    items.sort();

    // 清空并重新插入
    c->clear();
    c->addItems(items);

    // 重新选中
    c->setInsertPolicy(QComboBox::NoInsert);    // 防止原项已经被删除或重命名了
    c->setCurrentText(currentT);
}

/* */

/* 用于处理
 * lineText的换行键按下
 *  */

bool ifReturnOrEnter(QEvent* event)
{
    if(event->type() != QEvent::KeyPress)
        return false;

    auto* keyEvent = static_cast<QKeyEvent*>(event);
    return keyEvent->key() == Qt::Key_Return ||
           keyEvent->key() == Qt::Key_Enter;
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{   
    // 处理newDBNameText和renameText回车键（主键盘 / 小键盘）
    if (obj == ui->newDBNameText || obj == ui->renameText)
        if (ifReturnOrEnter(event))
        {
            on_operateButton_clicked();
            return true; // 拦截事件
        }

    // 处理tableNameText回车
    if(obj == ui->tableNameText)
        if(ifReturnOrEnter(event))
        {
            on_openSqlViewButton_clicked();
            return true;
        }

    // 处理folderAddText回车
    if(obj == ui->folderAddText)
        if(ifReturnOrEnter(event))
        {
            on_folderAddButton_clicked();
            return true;
        }

    // 其他交给基类
    return QMainWindow::eventFilter(obj, event);
}

/* */

/* tableview用 */

void MainWindow::onDBTableContextMenu(const QPoint &pos)
{
    QMenu menu(this);

    QAction *insertRow = menu.addAction("追加行");
    QAction *deleteRow = menu.addAction("删除行");

    QAction *selectedAction = menu.exec(ui->dbTable->viewport()->mapToGlobal(pos));
    if (!selectedAction) return;

    if (selectedAction == insertRow)
    {
        int row = model->rowCount();
        model->insertRow(row);
        return;
    }
    if (selectedAction == deleteRow)
    {
        QModelIndex index = ui->dbTable->indexAt(pos);
        int row = index.row();
        model->removeRow(row);
        return;
    }
}

/* */

/* VSCode */

void MainWindow::on_folderAddButton_clicked()
{
    QString newFolder = ui->folderAddText->displayText();
    changeSlash(newFolder);

    // 检查是否未输入内容
    if(!newFolder.size())
    {
        defaultError("未输入任何内容。");
        return;
    }

    if(ui->foldersCCB->findText(newFolder)==-1) // 不存在这个文件夹链接才插入
    {
        ui->foldersCCB->setInsertPolicy(QComboBox::InsertAlphabetically);
        ui->foldersCCB->addItem(newFolder);
        tip(ui->centralwidget, "成功添加。" + newFolder);
    }
    else
        tip(ui->centralwidget, newFolder + "已经存在。");
}

void MainWindow::on_folderDelButton_clicked()
{
    if(!ui->foldersCCB->count())
        defaultError("尚无文件夹链接存在。");
    else
    {
        int index = ui->foldersCCB->currentIndex();
        ui->foldersCCB->removeItem(index);
    }
}

void MainWindow::on_openVSCodeButton_clicked()
{
    QString folder = ui->foldersCCB->currentText();

    // 检查是否为空
    if(!folder.size())
    {
        defaultError("没有可以打开的文件夹链接。");
        return;
    }

    QString vsDevCmd = ui->vsDevCmdAddrText->displayText();
    if(!vsDevCmd.size())
    {
        defaultError("请输入Developer Command Prompt for VS 2022的地址");
        return;
    }

    openFolderInVSCode(folder, vsDevCmd);

    if(ui->shutdownForVSCodeBox->isChecked())
        shutdown(ui);
}

/* */

