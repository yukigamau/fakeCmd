#ifndef SQL_H
#define SQL_H

#include <QComboBox>
#include <QListWidget>
#include <QSqlDatabase>
#include <QString>
#include <vector>
#include "mainwindow.h"

using std::map, std::pair, std::vector;

// 创建存储数据用的数据库
void createStoreDB();
void readStoreDB(_Out_ map<QString, QString>& read);
void updateStoreDB(vector<pair<QString, QString>>& data);

// 用于DBFileChangePage
void delDB(QComboBox* ccb, const QStringList& name, QWidget* w);
void newDB(const QString& name, _Out_ Ui::MainWindow* ui);
bool renDB(const QString& old, _Out_ QString& cur, bool ifSaveAddr, QWidget* w);

// 用于读取QComboBox与输出到QListWidget
void makeCCBChecks(QComboBox* ccb, QListWidget* ls);

// 控件工具
void tip(QWidget* w, const QString& text);

#endif // SQL_H
