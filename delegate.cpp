#include "delegate.h"
#include <QKeyEvent>
#include <QFocusEvent>

MyDelegate::MyDelegate(QObject* parent)
    : QStyledItemDelegate(parent)
{
}

QWidget* MyDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem&,
                      const QModelIndex&) const
{
    QLineEdit* editor = new QLineEdit(parent);
    editor->setFrame(false);
    editor->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    editor->setStyleSheet("QLineEdit {color: black;"
                          "background-color: white;}");

    return editor;
}

void MyDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();
    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(editor);
    if (lineEdit) lineEdit->setText(value);
}

void MyDelegate::setModelData(QWidget* editor, QAbstractItemModel* model,
                  const QModelIndex& index) const
{
    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(editor);
    if (lineEdit) model->setData(index, lineEdit->text(), Qt::EditRole);
}
