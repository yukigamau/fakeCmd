#include "error.h"
#include <QDir>
#include <QProcess>

void openFolderInVSCode(QString& folderPath, QString& vsDevCmd)
{
    // 创建临时批处理文件
    QString batchContent = QString(
                               "@echo off\n"
                               "call \"%1\"\n"
                               "cd \"%2\"\n"
                               "code .\n"
                               ).arg(vsDevCmd, folderPath);

    QString batchFile = "open_vscode.bat";

    QFile file(batchFile);
    if (!file.open(QIODevice::ReadWrite))
    {
        defaultError("无法创建临时批处理文件");
        return;
    }
    file.resize(0);
    file.write(batchContent.toLocal8Bit());
    file.close();

    // 使用startDetached启动，不阻塞UI
    QProcess::startDetached("cmd.exe", {"/c", QString("%1").arg(batchFile)});
}
