#include <QApplication>
#include <QCheckBox>

void shutdown(QCheckBox* cb)
{
    if(cb->isChecked())
        QApplication::quit();
}
