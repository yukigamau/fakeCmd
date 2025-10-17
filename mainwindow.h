#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <string>

const std::string DB="db.txt";

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    // 用于tableView显示表格
    QSqlTableModel *model;

private slots:
    // 工具页面
    void on_addButton_clicked();
    void on_deepseekButton_clicked();
    void on_diyButton_clicked();
    void on_doubaoButton_clicked();

    // 选择页面
    void on_schoolPageButton_toggled();
    void on_sqlitePageButton_toggled();
    void on_toolPageButton_toggled();
    void on_vscodePageButton_toggled();

    // 校园网服务
    void on_chooseClassButton_clicked();
    void on_documentButton_clicked();
    void on_hallButton_clicked();
    void on_websiteButton_clicked();

    // Sqlite3
    void on_backButton_clicked();
    void on_dbFilesChangeButton_clicked();
    void on_openSqlViewButton_clicked();
    void on_operateButton_clicked();
    void on_operateCCB_currentIndexChanged();
    void on_runSqlButton_clicked();
    void on_saveButton_clicked();

    // tableview用
    void onDBTableContextMenu(const QPoint &pos);

    // VSCode
    void on_folderAddButton_clicked();
    void on_folderDelButton_clicked();
    void on_openVSCodeButton_clicked();

protected:
    // 用于处理lineText的换行键按下的问题
    bool eventFilter(QObject* obj, QEvent* event) override;
};
#endif // MAINWINDOW_H
