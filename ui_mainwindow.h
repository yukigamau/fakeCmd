/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *pageSelectBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *schoolPageButton;
    QRadioButton *sqlitePageButton;
    QRadioButton *vscodePageButton;
    QRadioButton *toolPageButton;
    QFrame *line_2;
    QStackedWidget *mainShowWidget;
    QWidget *schoolPage;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLineEdit *chooseClassText;
    QLabel *label_2;
    QPushButton *websiteButton;
    QLineEdit *hallText;
    QPushButton *hallButton;
    QLabel *websiteLabel;
    QCheckBox *shutdownBox;
    QLineEdit *websiteText;
    QPushButton *chooseClassButton;
    QLabel *chooseClassLable;
    QPushButton *documentButton;
    QLabel *label_3;
    QLineEdit *documentText;
    QSpacerItem *verticalSpacer;
    QWidget *sqlitePage;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_7;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_8;
    QComboBox *dbFilesChangeCCB;
    QVBoxLayout *verticalLayout_4;
    QPushButton *dbFilesChangeButton;
    QLineEdit *tableNameText;
    QPushButton *openSqlViewButton;
    QPushButton *runSqlButton;
    QPlainTextEdit *runSqlText;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *saveButton;
    QTableView *dbTable;
    QWidget *vscodePage;
    QGridLayout *gridLayout_8;
    QPushButton *openVSCodeButton;
    QPushButton *folderDelButton;
    QLineEdit *folderAddText;
    QSpacerItem *verticalSpacer_2;
    QPushButton *folderAddButton;
    QComboBox *foldersCCB;
    QLabel *label_6;
    QCheckBox *shutdownForVSCodeBox;
    QLabel *label_16;
    QLineEdit *vsDevCmdAddrText;
    QWidget *toolPage;
    QGridLayout *gridLayout_3;
    QLabel *label_18;
    QLabel *label_20;
    QLabel *label_22;
    QPushButton *diyButton;
    QLineEdit *addText;
    QPushButton *addButton;
    QLineEdit *doubaoText;
    QCheckBox *shutdownForToolBox;
    QLineEdit *deepseekText;
    QPushButton *doubaoButton;
    QLabel *label_17;
    QLabel *label_21;
    QLineEdit *zlibraryText;
    QFrame *line;
    QPushButton *deepseekButton;
    QComboBox *diyCCB;
    QPushButton *chatgptButton;
    QPushButton *zlibraryButton;
    QLineEdit *chatgptText;
    QLabel *label_19;
    QSpacerItem *verticalSpacer_4;
    QFrame *line_3;
    QPushButton *diyDelButton;
    QWidget *dbFilesChangePage;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *backButton;
    QComboBox *operateCCB;
    QPushButton *operateButton;
    QLabel *label_10;
    QLabel *label_11;
    QStackedWidget *operatorPage;
    QWidget *newOperator;
    QGridLayout *gridLayout_4;
    QLineEdit *newDBNameText;
    QLabel *label_12;
    QSpacerItem *verticalSpacer_3;
    QWidget *deleteOperator;
    QGridLayout *gridLayout_5;
    QLabel *label_13;
    QListWidget *DBList;
    QCheckBox *ifDelFileBox;
    QWidget *renameOperator;
    QGridLayout *gridLayout_6;
    QComboBox *renameCCB;
    QLabel *label_15;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *renameText;
    QLabel *label_14;
    QCheckBox *addrSaveButton;
    QLabel *label_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(806, 683);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamilies({QString::fromUtf8("\346\226\260\345\256\213\344\275\223")});
        font.setPointSize(18);
        centralwidget->setFont(font);
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pageSelectBox = new QGroupBox(centralwidget);
        pageSelectBox->setObjectName("pageSelectBox");
        pageSelectBox->setFlat(false);
        horizontalLayout_2 = new QHBoxLayout(pageSelectBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        schoolPageButton = new QRadioButton(pageSelectBox);
        schoolPageButton->setObjectName("schoolPageButton");
        schoolPageButton->setCheckable(true);
        schoolPageButton->setChecked(true);

        horizontalLayout_2->addWidget(schoolPageButton);

        sqlitePageButton = new QRadioButton(pageSelectBox);
        sqlitePageButton->setObjectName("sqlitePageButton");

        horizontalLayout_2->addWidget(sqlitePageButton);

        vscodePageButton = new QRadioButton(pageSelectBox);
        vscodePageButton->setObjectName("vscodePageButton");

        horizontalLayout_2->addWidget(vscodePageButton);

        toolPageButton = new QRadioButton(pageSelectBox);
        toolPageButton->setObjectName("toolPageButton");

        horizontalLayout_2->addWidget(toolPageButton);


        horizontalLayout->addWidget(pageSelectBox);


        verticalLayout_5->addLayout(horizontalLayout);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_5->addWidget(line_2);

        mainShowWidget = new QStackedWidget(centralwidget);
        mainShowWidget->setObjectName("mainShowWidget");
        schoolPage = new QWidget();
        schoolPage->setObjectName("schoolPage");
        verticalLayout_2 = new QVBoxLayout(schoolPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        chooseClassText = new QLineEdit(schoolPage);
        chooseClassText->setObjectName("chooseClassText");

        gridLayout_2->addWidget(chooseClassText, 2, 3, 1, 1);

        label_2 = new QLabel(schoolPage);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 3, 1, 1, 1);

        websiteButton = new QPushButton(schoolPage);
        websiteButton->setObjectName("websiteButton");

        gridLayout_2->addWidget(websiteButton, 1, 0, 1, 1);

        hallText = new QLineEdit(schoolPage);
        hallText->setObjectName("hallText");

        gridLayout_2->addWidget(hallText, 3, 3, 1, 1);

        hallButton = new QPushButton(schoolPage);
        hallButton->setObjectName("hallButton");

        gridLayout_2->addWidget(hallButton, 3, 0, 1, 1);

        websiteLabel = new QLabel(schoolPage);
        websiteLabel->setObjectName("websiteLabel");

        gridLayout_2->addWidget(websiteLabel, 1, 1, 1, 1);

        shutdownBox = new QCheckBox(schoolPage);
        shutdownBox->setObjectName("shutdownBox");
        shutdownBox->setIconSize(QSize(12, 12));
        shutdownBox->setChecked(true);

        gridLayout_2->addWidget(shutdownBox, 5, 0, 1, 1);

        websiteText = new QLineEdit(schoolPage);
        websiteText->setObjectName("websiteText");

        gridLayout_2->addWidget(websiteText, 1, 3, 1, 1);

        chooseClassButton = new QPushButton(schoolPage);
        chooseClassButton->setObjectName("chooseClassButton");

        gridLayout_2->addWidget(chooseClassButton, 2, 0, 1, 1);

        chooseClassLable = new QLabel(schoolPage);
        chooseClassLable->setObjectName("chooseClassLable");

        gridLayout_2->addWidget(chooseClassLable, 2, 1, 1, 1);

        documentButton = new QPushButton(schoolPage);
        documentButton->setObjectName("documentButton");

        gridLayout_2->addWidget(documentButton, 4, 0, 1, 1);

        label_3 = new QLabel(schoolPage);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 4, 1, 1, 1);

        documentText = new QLineEdit(schoolPage);
        documentText->setObjectName("documentText");

        gridLayout_2->addWidget(documentText, 4, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        mainShowWidget->addWidget(schoolPage);
        sqlitePage = new QWidget();
        sqlitePage->setObjectName("sqlitePage");
        verticalLayout = new QVBoxLayout(sqlitePage);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(-1, -1, -1, 0);
        label_9 = new QLabel(sqlitePage);
        label_9->setObjectName("label_9");

        gridLayout_7->addWidget(label_9, 4, 1, 1, 1);

        label_7 = new QLabel(sqlitePage);
        label_7->setObjectName("label_7");

        gridLayout_7->addWidget(label_7, 2, 1, 1, 1);

        label_8 = new QLabel(sqlitePage);
        label_8->setObjectName("label_8");
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);

        gridLayout_7->addWidget(label_8, 0, 1, 1, 1);

        dbFilesChangeCCB = new QComboBox(sqlitePage);
        dbFilesChangeCCB->setObjectName("dbFilesChangeCCB");

        gridLayout_7->addWidget(dbFilesChangeCCB, 0, 2, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        dbFilesChangeButton = new QPushButton(sqlitePage);
        dbFilesChangeButton->setObjectName("dbFilesChangeButton");

        verticalLayout_4->addWidget(dbFilesChangeButton);


        gridLayout_7->addLayout(verticalLayout_4, 0, 0, 1, 1);

        tableNameText = new QLineEdit(sqlitePage);
        tableNameText->setObjectName("tableNameText");

        gridLayout_7->addWidget(tableNameText, 2, 2, 1, 1);

        openSqlViewButton = new QPushButton(sqlitePage);
        openSqlViewButton->setObjectName("openSqlViewButton");

        gridLayout_7->addWidget(openSqlViewButton, 2, 0, 1, 1);

        runSqlButton = new QPushButton(sqlitePage);
        runSqlButton->setObjectName("runSqlButton");

        gridLayout_7->addWidget(runSqlButton, 4, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_7);

        runSqlText = new QPlainTextEdit(sqlitePage);
        runSqlText->setObjectName("runSqlText");
        sizePolicy.setHeightForWidth(runSqlText->sizePolicy().hasHeightForWidth());
        runSqlText->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(runSqlText);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(sqlitePage);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        saveButton = new QPushButton(sqlitePage);
        saveButton->setObjectName("saveButton");

        horizontalLayout_3->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout_3);

        dbTable = new QTableView(sqlitePage);
        dbTable->setObjectName("dbTable");

        verticalLayout->addWidget(dbTable);

        mainShowWidget->addWidget(sqlitePage);
        vscodePage = new QWidget();
        vscodePage->setObjectName("vscodePage");
        gridLayout_8 = new QGridLayout(vscodePage);
        gridLayout_8->setObjectName("gridLayout_8");
        openVSCodeButton = new QPushButton(vscodePage);
        openVSCodeButton->setObjectName("openVSCodeButton");

        gridLayout_8->addWidget(openVSCodeButton, 4, 0, 1, 1);

        folderDelButton = new QPushButton(vscodePage);
        folderDelButton->setObjectName("folderDelButton");

        gridLayout_8->addWidget(folderDelButton, 2, 0, 1, 1);

        folderAddText = new QLineEdit(vscodePage);
        folderAddText->setObjectName("folderAddText");

        gridLayout_8->addWidget(folderAddText, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_8->addItem(verticalSpacer_2, 6, 0, 1, 1);

        folderAddButton = new QPushButton(vscodePage);
        folderAddButton->setObjectName("folderAddButton");

        gridLayout_8->addWidget(folderAddButton, 1, 0, 1, 1);

        foldersCCB = new QComboBox(vscodePage);
        foldersCCB->setObjectName("foldersCCB");

        gridLayout_8->addWidget(foldersCCB, 0, 1, 1, 1);

        label_6 = new QLabel(vscodePage);
        label_6->setObjectName("label_6");

        gridLayout_8->addWidget(label_6, 0, 0, 1, 1);

        shutdownForVSCodeBox = new QCheckBox(vscodePage);
        shutdownForVSCodeBox->setObjectName("shutdownForVSCodeBox");

        gridLayout_8->addWidget(shutdownForVSCodeBox, 5, 0, 1, 1);

        label_16 = new QLabel(vscodePage);
        label_16->setObjectName("label_16");

        gridLayout_8->addWidget(label_16, 3, 0, 1, 1);

        vsDevCmdAddrText = new QLineEdit(vscodePage);
        vsDevCmdAddrText->setObjectName("vsDevCmdAddrText");

        gridLayout_8->addWidget(vsDevCmdAddrText, 3, 1, 1, 1);

        mainShowWidget->addWidget(vscodePage);
        toolPage = new QWidget();
        toolPage->setObjectName("toolPage");
        gridLayout_3 = new QGridLayout(toolPage);
        gridLayout_3->setObjectName("gridLayout_3");
        label_18 = new QLabel(toolPage);
        label_18->setObjectName("label_18");

        gridLayout_3->addWidget(label_18, 2, 0, 1, 1);

        label_20 = new QLabel(toolPage);
        label_20->setObjectName("label_20");

        gridLayout_3->addWidget(label_20, 14, 0, 1, 1);

        label_22 = new QLabel(toolPage);
        label_22->setObjectName("label_22");

        gridLayout_3->addWidget(label_22, 4, 0, 1, 1);

        diyButton = new QPushButton(toolPage);
        diyButton->setObjectName("diyButton");

        gridLayout_3->addWidget(diyButton, 12, 0, 1, 1);

        addText = new QLineEdit(toolPage);
        addText->setObjectName("addText");

        gridLayout_3->addWidget(addText, 14, 1, 1, 1);

        addButton = new QPushButton(toolPage);
        addButton->setObjectName("addButton");

        gridLayout_3->addWidget(addButton, 15, 0, 1, 1);

        doubaoText = new QLineEdit(toolPage);
        doubaoText->setObjectName("doubaoText");

        gridLayout_3->addWidget(doubaoText, 2, 1, 1, 1);

        shutdownForToolBox = new QCheckBox(toolPage);
        shutdownForToolBox->setObjectName("shutdownForToolBox");

        gridLayout_3->addWidget(shutdownForToolBox, 16, 0, 1, 1);

        deepseekText = new QLineEdit(toolPage);
        deepseekText->setObjectName("deepseekText");

        gridLayout_3->addWidget(deepseekText, 6, 1, 1, 1);

        doubaoButton = new QPushButton(toolPage);
        doubaoButton->setObjectName("doubaoButton");

        gridLayout_3->addWidget(doubaoButton, 3, 0, 1, 1);

        label_17 = new QLabel(toolPage);
        label_17->setObjectName("label_17");

        gridLayout_3->addWidget(label_17, 6, 0, 1, 1);

        label_21 = new QLabel(toolPage);
        label_21->setObjectName("label_21");

        gridLayout_3->addWidget(label_21, 8, 0, 1, 1);

        zlibraryText = new QLineEdit(toolPage);
        zlibraryText->setObjectName("zlibraryText");

        gridLayout_3->addWidget(zlibraryText, 8, 1, 1, 1);

        line = new QFrame(toolPage);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_3->addWidget(line, 10, 0, 1, 1);

        deepseekButton = new QPushButton(toolPage);
        deepseekButton->setObjectName("deepseekButton");

        gridLayout_3->addWidget(deepseekButton, 7, 0, 1, 1);

        diyCCB = new QComboBox(toolPage);
        diyCCB->setObjectName("diyCCB");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(diyCCB->sizePolicy().hasHeightForWidth());
        diyCCB->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(diyCCB, 11, 1, 1, 1);

        chatgptButton = new QPushButton(toolPage);
        chatgptButton->setObjectName("chatgptButton");

        gridLayout_3->addWidget(chatgptButton, 5, 0, 1, 1);

        zlibraryButton = new QPushButton(toolPage);
        zlibraryButton->setObjectName("zlibraryButton");

        gridLayout_3->addWidget(zlibraryButton, 9, 0, 1, 1);

        chatgptText = new QLineEdit(toolPage);
        chatgptText->setObjectName("chatgptText");

        gridLayout_3->addWidget(chatgptText, 4, 1, 1, 1);

        label_19 = new QLabel(toolPage);
        label_19->setObjectName("label_19");

        gridLayout_3->addWidget(label_19, 11, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 17, 0, 1, 1);

        line_3 = new QFrame(toolPage);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_3->addWidget(line_3, 10, 1, 1, 1);

        diyDelButton = new QPushButton(toolPage);
        diyDelButton->setObjectName("diyDelButton");

        gridLayout_3->addWidget(diyDelButton, 13, 0, 1, 1);

        mainShowWidget->addWidget(toolPage);
        dbFilesChangePage = new QWidget();
        dbFilesChangePage->setObjectName("dbFilesChangePage");
        verticalLayout_3 = new QVBoxLayout(dbFilesChangePage);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 5, 1, 1);

        backButton = new QPushButton(dbFilesChangePage);
        backButton->setObjectName("backButton");

        gridLayout->addWidget(backButton, 0, 0, 1, 1);

        operateCCB = new QComboBox(dbFilesChangePage);
        operateCCB->addItem(QString());
        operateCCB->addItem(QString());
        operateCCB->addItem(QString());
        operateCCB->setObjectName("operateCCB");

        gridLayout->addWidget(operateCCB, 1, 1, 1, 1);

        operateButton = new QPushButton(dbFilesChangePage);
        operateButton->setObjectName("operateButton");

        gridLayout->addWidget(operateButton, 1, 3, 1, 1);

        label_10 = new QLabel(dbFilesChangePage);
        label_10->setObjectName("label_10");
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_10, 1, 0, 1, 1);

        label_11 = new QLabel(dbFilesChangePage);
        label_11->setObjectName("label_11");

        gridLayout->addWidget(label_11, 1, 4, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        operatorPage = new QStackedWidget(dbFilesChangePage);
        operatorPage->setObjectName("operatorPage");
        newOperator = new QWidget();
        newOperator->setObjectName("newOperator");
        gridLayout_4 = new QGridLayout(newOperator);
        gridLayout_4->setObjectName("gridLayout_4");
        newDBNameText = new QLineEdit(newOperator);
        newDBNameText->setObjectName("newDBNameText");

        gridLayout_4->addWidget(newDBNameText, 0, 1, 1, 1);

        label_12 = new QLabel(newOperator);
        label_12->setObjectName("label_12");
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(label_12, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 2, 0, 1, 1);

        operatorPage->addWidget(newOperator);
        deleteOperator = new QWidget();
        deleteOperator->setObjectName("deleteOperator");
        gridLayout_5 = new QGridLayout(deleteOperator);
        gridLayout_5->setObjectName("gridLayout_5");
        label_13 = new QLabel(deleteOperator);
        label_13->setObjectName("label_13");

        gridLayout_5->addWidget(label_13, 1, 0, 1, 1);

        DBList = new QListWidget(deleteOperator);
        DBList->setObjectName("DBList");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(DBList->sizePolicy().hasHeightForWidth());
        DBList->setSizePolicy(sizePolicy4);

        gridLayout_5->addWidget(DBList, 2, 0, 1, 1);

        ifDelFileBox = new QCheckBox(deleteOperator);
        ifDelFileBox->setObjectName("ifDelFileBox");

        gridLayout_5->addWidget(ifDelFileBox, 0, 0, 1, 1);

        operatorPage->addWidget(deleteOperator);
        renameOperator = new QWidget();
        renameOperator->setObjectName("renameOperator");
        gridLayout_6 = new QGridLayout(renameOperator);
        gridLayout_6->setObjectName("gridLayout_6");
        renameCCB = new QComboBox(renameOperator);
        renameCCB->setObjectName("renameCCB");

        gridLayout_6->addWidget(renameCCB, 0, 2, 1, 1);

        label_15 = new QLabel(renameOperator);
        label_15->setObjectName("label_15");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(label_15, 1, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer_5, 3, 0, 1, 1);

        renameText = new QLineEdit(renameOperator);
        renameText->setObjectName("renameText");

        gridLayout_6->addWidget(renameText, 1, 2, 1, 1);

        label_14 = new QLabel(renameOperator);
        label_14->setObjectName("label_14");
        sizePolicy5.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy5);

        gridLayout_6->addWidget(label_14, 0, 0, 1, 1);

        addrSaveButton = new QCheckBox(renameOperator);
        addrSaveButton->setObjectName("addrSaveButton");
        addrSaveButton->setChecked(true);

        gridLayout_6->addWidget(addrSaveButton, 2, 0, 1, 1);

        label_4 = new QLabel(renameOperator);
        label_4->setObjectName("label_4");

        gridLayout_6->addWidget(label_4, 2, 2, 1, 1);

        operatorPage->addWidget(renameOperator);

        verticalLayout_3->addWidget(operatorPage);

        mainShowWidget->addWidget(dbFilesChangePage);

        verticalLayout_5->addWidget(mainShowWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\201\207\345\221\275\344\273\244\350\241\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\210\266\344\275\234\357\274\232yukigamau|\347\211\210\346\234\254\357\274\2321.5.0", nullptr));
        pageSelectBox->setTitle(QString());
        schoolPageButton->setText(QCoreApplication::translate("MainWindow", "\346\240\241\345\233\255\346\234\215\345\212\241(a)", nullptr));
#if QT_CONFIG(shortcut)
        schoolPageButton->setShortcut(QCoreApplication::translate("MainWindow", "A", nullptr));
#endif // QT_CONFIG(shortcut)
        sqlitePageButton->setText(QCoreApplication::translate("MainWindow", "sqlite3(b)", nullptr));
#if QT_CONFIG(shortcut)
        sqlitePageButton->setShortcut(QCoreApplication::translate("MainWindow", "B", nullptr));
#endif // QT_CONFIG(shortcut)
        vscodePageButton->setText(QCoreApplication::translate("MainWindow", "VSCode(c)", nullptr));
#if QT_CONFIG(shortcut)
        vscodePageButton->setShortcut(QCoreApplication::translate("MainWindow", "C", nullptr));
#endif // QT_CONFIG(shortcut)
        toolPageButton->setText(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267(d)", nullptr));
#if QT_CONFIG(shortcut)
        toolPageButton->setShortcut(QCoreApplication::translate("MainWindow", "D", nullptr));
#endif // QT_CONFIG(shortcut)
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\212\236\344\272\213\345\244\247\345\216\205\357\274\232", nullptr));
        websiteButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\212\347\275\221\347\231\273\345\275\225\351\241\265\351\235\242(e)", nullptr));
#if QT_CONFIG(shortcut)
        websiteButton->setShortcut(QCoreApplication::translate("MainWindow", "E", nullptr));
#endif // QT_CONFIG(shortcut)
        hallButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\212\236\344\272\213\345\244\247\345\216\205(g)", nullptr));
#if QT_CONFIG(shortcut)
        hallButton->setShortcut(QCoreApplication::translate("MainWindow", "G", nullptr));
#endif // QT_CONFIG(shortcut)
        websiteLabel->setText(QCoreApplication::translate("MainWindow", "\344\270\212\347\275\221\347\231\273\345\275\225\347\275\221\345\235\200\357\274\232", nullptr));
        shutdownBox->setText(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\345\220\216\345\205\263\351\227\255\347\250\213\345\272\217(i)", nullptr));
#if QT_CONFIG(shortcut)
        shutdownBox->setShortcut(QCoreApplication::translate("MainWindow", "I", nullptr));
#endif // QT_CONFIG(shortcut)
        chooseClassButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\351\200\211\350\257\276\347\275\221\347\253\231(f)", nullptr));
#if QT_CONFIG(shortcut)
        chooseClassButton->setShortcut(QCoreApplication::translate("MainWindow", "F", nullptr));
#endif // QT_CONFIG(shortcut)
        chooseClassLable->setText(QCoreApplication::translate("MainWindow", "\351\200\211\350\257\276\351\241\265\351\235\242\357\274\232", nullptr));
        documentButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\205\254\346\226\207\351\200\232(h)", nullptr));
#if QT_CONFIG(shortcut)
        documentButton->setShortcut(QCoreApplication::translate("MainWindow", "H", nullptr));
#endif // QT_CONFIG(shortcut)
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\205\254\346\226\207\351\200\232\345\234\260\345\235\200\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\344\273\243\347\240\201\342\206\223", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\241\250\346\240\274\345\220\215\347\247\260\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\345\234\260\345\235\200\357\274\232", nullptr));
        dbFilesChangeButton->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\346\225\260\346\215\256\345\272\223\345\220\215\345\215\225(e)", nullptr));
#if QT_CONFIG(shortcut)
        dbFilesChangeButton->setShortcut(QCoreApplication::translate("MainWindow", "E", nullptr));
#endif // QT_CONFIG(shortcut)
        openSqlViewButton->setText(QCoreApplication::translate("MainWindow", "\350\241\250\350\247\206\345\233\276(F5)", nullptr));
#if QT_CONFIG(shortcut)
        openSqlViewButton->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        runSqlButton->setText(QCoreApplication::translate("MainWindow", "\346\211\247\350\241\214(ctrl+r)", nullptr));
#if QT_CONFIG(shortcut)
        runSqlButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "\350\241\250\350\247\206\345\233\276\342\206\223", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250\344\277\256\346\224\271(ctrl+s)", nullptr));
#if QT_CONFIG(shortcut)
        saveButton->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        openVSCodeButton->setText(QCoreApplication::translate("MainWindow", "\351\205\215\347\275\256MSVC\347\216\257\345\242\203\346\211\223\345\274\200VSCode(g)", nullptr));
#if QT_CONFIG(shortcut)
        openVSCodeButton->setShortcut(QCoreApplication::translate("MainWindow", "G", nullptr));
#endif // QT_CONFIG(shortcut)
        folderDelButton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\226\207\344\273\266\345\244\271\351\223\276\346\216\245(f)", nullptr));
#if QT_CONFIG(shortcut)
        folderDelButton->setShortcut(QCoreApplication::translate("MainWindow", "F", nullptr));
#endif // QT_CONFIG(shortcut)
        folderAddButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266\345\244\271\351\223\276\346\216\245", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\345\244\271\357\274\232", nullptr));
        shutdownForVSCodeBox->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\220\257\345\220\216\345\205\263\351\227\255\347\250\213\345\272\217(h)", nullptr));
#if QT_CONFIG(shortcut)
        shutdownForVSCodeBox->setShortcut(QCoreApplication::translate("MainWindow", "H", nullptr));
#endif // QT_CONFIG(shortcut)
        label_16->setText(QCoreApplication::translate("MainWindow", "MSVC\345\221\275\344\273\244\350\241\214\345\234\260\345\235\200\357\274\232", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\350\261\206\345\214\205\357\274\232", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\357\274\232", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "ChatGPT\357\274\232", nullptr));
        diyButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(i)", nullptr));
#if QT_CONFIG(shortcut)
        diyButton->setShortcut(QCoreApplication::translate("MainWindow", "I", nullptr));
#endif // QT_CONFIG(shortcut)
        addButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240(k)", nullptr));
#if QT_CONFIG(shortcut)
        addButton->setShortcut(QCoreApplication::translate("MainWindow", "K", nullptr));
#endif // QT_CONFIG(shortcut)
        doubaoText->setText(QCoreApplication::translate("MainWindow", "https://www.doubao.com/chat/", nullptr));
        shutdownForToolBox->setText(QCoreApplication::translate("MainWindow", "\347\224\250\345\220\216\345\205\263\351\227\255(l)", nullptr));
#if QT_CONFIG(shortcut)
        shutdownForToolBox->setShortcut(QCoreApplication::translate("MainWindow", "L", nullptr));
#endif // QT_CONFIG(shortcut)
        deepseekText->setText(QCoreApplication::translate("MainWindow", "https://chat.deepseek.com/", nullptr));
        doubaoButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(e)", nullptr));
#if QT_CONFIG(shortcut)
        doubaoButton->setShortcut(QCoreApplication::translate("MainWindow", "E", nullptr));
#endif // QT_CONFIG(shortcut)
        label_17->setText(QCoreApplication::translate("MainWindow", "DeepSeek\357\274\232", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "ZLibrary\357\274\232", nullptr));
        zlibraryText->setText(QCoreApplication::translate("MainWindow", "https://zh.z-library.sk/", nullptr));
        deepseekButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(g)", nullptr));
#if QT_CONFIG(shortcut)
        deepseekButton->setShortcut(QCoreApplication::translate("MainWindow", "G", nullptr));
#endif // QT_CONFIG(shortcut)
        chatgptButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(f)", nullptr));
#if QT_CONFIG(shortcut)
        chatgptButton->setShortcut(QCoreApplication::translate("MainWindow", "F", nullptr));
#endif // QT_CONFIG(shortcut)
        zlibraryButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(h)", nullptr));
#if QT_CONFIG(shortcut)
        zlibraryButton->setShortcut(QCoreApplication::translate("MainWindow", "H", nullptr));
#endif // QT_CONFIG(shortcut)
        chatgptText->setText(QCoreApplication::translate("MainWindow", "www.chatgpt.com", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211\357\274\232", nullptr));
        diyDelButton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244(j)", nullptr));
#if QT_CONFIG(shortcut)
        diyDelButton->setShortcut(QCoreApplication::translate("MainWindow", "J", nullptr));
#endif // QT_CONFIG(shortcut)
        backButton->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236(ESC)", nullptr));
#if QT_CONFIG(shortcut)
        backButton->setShortcut(QCoreApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        operateCCB->setItemText(0, QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
        operateCCB->setItemText(1, QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        operateCCB->setItemText(2, QCoreApplication::translate("MainWindow", "\346\224\271\345\220\215", nullptr));

        operateButton->setText(QCoreApplication::translate("MainWindow", "\346\211\247\350\241\214(r)", nullptr));
#if QT_CONFIG(shortcut)
        operateButton->setShortcut(QCoreApplication::translate("MainWindow", "R", nullptr));
#endif // QT_CONFIG(shortcut)
        label_10->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\223\215\344\275\234\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\345\220\216\344\270\215\345\217\257\346\222\244\345\233\236", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266\347\232\204\345\220\215\347\247\260\357\274\232\n"
"\350\246\201\345\270\246\344\270\212\345\220\216\347\274\200\345\220\215\n"
"\350\257\267\344\275\277\347\224\250\346\240\207\345\207\206\347\232\204\345\234\260\345\235\200\345\206\231\346\263\225", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\350\246\201\345\210\240\351\231\244\347\232\204\346\226\207\344\273\266\357\274\232", nullptr));
        ifDelFileBox->setText(QCoreApplication::translate("MainWindow", "\345\220\214\346\227\266\345\210\240\351\231\244\346\226\207\344\273\266", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\221\275\345\220\215\347\232\204\345\220\215\345\255\227\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\350\246\201\351\207\215\345\221\275\345\220\215\347\232\204\346\226\207\344\273\266\357\274\232", nullptr));
        addrSaveButton->setText(QCoreApplication::translate("MainWindow", "\345\234\250\345\216\237\350\267\257\345\276\204\344\270\213\344\277\256\346\224\271", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\246\202\346\236\234\345\217\226\346\266\210\345\213\276\351\200\211\357\274\214\350\257\267\344\277\235\350\257\201\350\276\223\345\205\245\347\232\204\345\220\215\345\255\227\345\214\205\345\220\253\345\234\260\345\235\200\344\277\241\346\201\257\343\200\202\n"
"\350\213\245\345\213\276\351\200\211\344\270\224\345\234\250\345\220\215\345\255\227\344\270\255\345\214\205\345\220\253\350\267\257\345\276\204\344\277\241\346\201\257\357\274\214\345\260\206\344\273\215\347\204\266\344\277\256\346\224\271\345\205\266\350\267\257\345\276\204\343\200\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
