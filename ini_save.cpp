#include "mainwindow.h"
#include "sql.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <string>
#include <type_traits>

using std::string;
using std::is_same_v;

/* 初始数据读取与样式修改 */

void styleChange()
{
    QApplication::setFont(QFont("新宋体", 18));
}

void ini(Ui::MainWindow* ui)
{
    styleChange();

    createStoreDB();

    map<QString, QString> read;

    // 校园服务
    read["website"]="";
    read["chooseClass"]="";
    read["hall"]="";
    read["document"]="";
    read["shutdown"]="";
    // sqlite3
    read["DBnum"]="";
    read["defaultDB"]="";
    // VSCode
    read["foldersNum"]="";
    read["defaultFolder"]="";
    read["vsDevCmdAddr"]="";
    read["shutdownForVSCode"]="";

    readStoreDB(read);

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

    int DBnum = read["DBnum"].toInt();
    map<QString, QString> DBread;
    for(int i = 0; i<DBnum; ++i)
        DBread[QString::number(i)]="";

    readStoreDB(DBread);
    for(int i = 0; i<DBnum; ++i)
    {
        const QString item = DBread[QString::number(i)];
        ui->dbFilesChangeCCB->addItem(item);
    }

    int defaultDB = read["defaultDB"].toInt();
    ui->dbFilesChangeCCB->setCurrentIndex(defaultDB);

    //

    // VSCode

    int foldersNum = read["foldersNum"].toInt();
    map<QString, QString> foldersread;
    for(int i = 0; i<foldersNum; ++i)
        foldersread["folder"+QString::number(i)]="";
    readStoreDB(foldersread);
    for(int i = 0; i<foldersNum; ++i)
    {
        const QString item = foldersread["folder"+QString::number(i)];
        ui->foldersCCB->addItem(item);
    }

    int defaultFolder =read["defaultFolder"].toInt();
    ui->foldersCCB->setCurrentIndex(defaultFolder);

    const QString vsDevCmdAddrText = read["vsDevCmdAddr"];
    ui->vsDevCmdAddrText->setText(vsDevCmdAddrText);

    bool shutdownForVSCode = read["shutdownForVSCode"].toInt();
    ui->shutdownForVSCodeBox->setChecked(shutdownForVSCode);

    //
}

/* */

/* 关闭程序时保存数据 */

void save(Ui::MainWindow* ui)
{
    vector<pair<QString, QString>> data;

    // 校园服务

    QString qs = ui->websiteText->displayText();
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

    const int DBnum = ui->dbFilesChangeCCB->count();
    qs = QString::number(DBnum);
    data.push_back(pair{"DBnum", qs});

    for(int i = 0; i<DBnum; ++i)
    {
        qs = ui->dbFilesChangeCCB->itemText(i);
        data.push_back(pair{QString::number(i), qs});
    }

    const int defaultDB = ui->dbFilesChangeCCB->currentIndex();
    qs = QString::number(defaultDB);
    data.push_back(pair{"defaultDB", qs});

    //

    // VSCode
    const int foldersNum = ui->foldersCCB->count();
    qs = QString::number(foldersNum);
    data.push_back(pair{"foldersNum", qs});

    for(int i=0;i<foldersNum;++i)
    {
        qs=ui->foldersCCB->itemText(i);
        data.push_back(pair{"folder"+QString::number(i),qs});
    }

    const int defaultFolder = ui->foldersCCB->currentIndex();
    qs = QString::number(defaultFolder);
    data.push_back(pair{"defaultFolder", qs});

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

void changeSlash(QString& s)
{
    for(QChar& c : s)
        if(c == '/')
            c = '\\';
}
