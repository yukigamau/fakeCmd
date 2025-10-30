#include "mainwindow.h"
#include "sql.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <string>
#include <type_traits>

using std::string;
using std::is_same_v;

/* 初始数据读取与样式修改 */

void CCBIni(map<QString,QString>&read,QString name,QComboBox* ccb)
{
    int num = read[name+"Num"].toInt();
    map<QString, QString> DBread;
    for(int i = 0; i<num; ++i)
        DBread[name+QString::number(i)]="";

    readStoreDB(DBread);
    for(int i = 0; i<num; ++i)
    {
        const QString item = DBread[name+QString::number(i)];
        ccb->addItem(item);
    }

    int defaultIndex =read["default"+name].toInt();
    ccb->setCurrentIndex(defaultIndex);
}

void ini(Ui::MainWindow* ui)
{
    createStoreDB();

    map<QString, QString> read;

    // 工具
    read["deepseek"]="";
    read["diyNum"]="";
    read["doubao"]="";
    read["shutdownForTool"]="";
    // 校园服务
    read["website"]="";
    read["chooseClass"]="";
    read["hall"]="";
    read["document"]="";
    read["shutdown"]="";
    // sqlite3
    read["DBNum"]="";
    read["defaultDB"]="";
    // VSCode
    read["foldersNum"]="";
    read["defaultfolders"]="";
    read["vsDevCmdAddr"]="";
    read["shutdownForVSCode"]="";

    readStoreDB(read);

    // 工具

    QString deepseek=read["deepseek"];
    if(deepseek.size())
        ui->deepseekText->setText(deepseek);

    CCBIni(read,"diy",ui->diyCCB);

    QString doubao=read["doubao"];
    if(doubao.size())
        ui->doubaoText->setText(doubao);

    bool shutdownForTool=read["shutdownForTool"].toInt();
    ui->shutdownForToolBox->setChecked(shutdownForTool);

    //

    // 校园服务

    QString website = read["website"];
    ui->websiteText->setText(website);

    QString chooseClass = read["chooseClass"];
    ui->chooseClassText->setText(chooseClass);

    QString hall = read["hall"];
    ui->hallText->setText(hall);

    QString document = read["document"];
    ui->documentText->setText(document);

    bool shutdown = read["shutdown"].toInt();
    ui->shutdownBox->setChecked(shutdown);

    //

    // sqlite3

    CCBIni(read,"DB",ui->dbFilesChangeCCB);

    //

    // VSCode

    CCBIni(read,"folders",ui->foldersCCB);

    const QString vsDevCmdAddrText = read["vsDevCmdAddr"];
    ui->vsDevCmdAddrText->setText(vsDevCmdAddrText);

    bool shutdownForVSCode = read["shutdownForVSCode"].toInt();
    ui->shutdownForVSCodeBox->setChecked(shutdownForVSCode);

    //
}

/* */

/* 关闭程序时保存数据 */

void CCBSave(vector<pair<QString,QString>>&data,QComboBox* ccb, QString name)
{
    const int num = ccb->count();
    QString qs = QString::number(num);
    data.push_back(pair{name+"Num", qs});

    for(int i = 0; i<num; ++i)
    {
        qs = ccb->itemText(i);
        data.push_back(pair{name+QString::number(i), qs});
    }

    const int defaultDB = ccb->currentIndex();
    qs = QString::number(defaultDB);
    data.push_back(pair{"default"+name, qs});
}

void save(Ui::MainWindow* ui)
{
    vector<pair<QString, QString>> data;

    // 工具

    QString qs = ui->deepseekText->displayText();
    data.push_back(pair{"deepseek",qs});

    CCBSave(data,ui->diyCCB,"diy");

    qs=ui->doubaoText->displayText();
    data.push_back(pair{"doubao",qs});

    if(ui->shutdownForToolBox->isChecked())
        qs="1";
    else
        qs="0";
    data.push_back(pair{"shutdownForTool",qs});

    // 校园服务

    qs = ui->websiteText->displayText();
    data.push_back(pair{"website", qs});

    qs = ui->chooseClassText->displayText();
    data.push_back(pair{"chooseClass", qs});

    qs = ui->hallText->displayText();
    data.push_back(pair{"hall", qs});

    qs = ui->documentText->displayText();
    data.push_back(pair{"document", qs});

    if(ui->shutdownBox->isChecked())
        qs = "1";
    else
        qs = "0";
    data.push_back(pair{"shutdown", qs});

    //

    // sqlite3

    CCBSave(data,ui->dbFilesChangeCCB,"DB");

    //

    // VSCode

    CCBSave(data,ui->foldersCCB,"folders");

    qs = ui->vsDevCmdAddrText->displayText();
    data.push_back(pair{"vsDevCmdAddr",qs});

    if(ui->shutdownForVSCodeBox->isChecked())
        qs = "1";
    else
        qs = "0";
    data.push_back(pair{"shutdownForVSCode", qs});

    updateStoreDB(data);
}

/* */

// 用于统一文件夹地址中的斜线
void changeSlash(QString& s)
{
    for(QChar& c : s)
        if(c == '/')
            c = '\\';
}
