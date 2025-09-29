#include "error.h"
#include "const.h"
#include <QMessageBox>

void defaultError(QString text)
{
    QMessageBox::warning(nullptr, errorTitle, text);
}
