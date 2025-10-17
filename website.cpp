#include "error.h"
#include "shutdown.h"
#include <QCheckBox>
#include <QDesktopServices>
#include <QString>
#include <QUrl>

void openWeb(QString qs, QCheckBox* cb)
{
    if(!QDesktopServices::openUrl(QUrl(qs)))
        defaultError("打开网页" + qs + "失败。");
    else
        shutdown(cb);
}
