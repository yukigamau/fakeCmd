#include "error.h"
#include "tip.h"
#include "ui_mainwindow.h"
#include <QComboBox>

void addCCBItem(QString qs,QComboBox* ccb,Ui::MainWindow* ui)
{
    // 检查是否未输入内容
    if(!qs.size())
    {
        defaultError("未输入任何内容。");
        return;
    }

    if(ccb->findText(qs)==-1) // 不存在这个文件夹链接才插入
    {
        ccb->setInsertPolicy(QComboBox::InsertAlphabetically);
        ccb->addItem(qs);
        tip(ui->centralwidget, "成功添加。" + qs);
    }
    else
        tip(ui->centralwidget, qs + "已经存在。");
}
