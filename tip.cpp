#include "tip.h"
#include <QLabel>
#include <QPropertyAnimation>
#include <QTimer>

void tip(QWidget* w, const QString& text)
{
    if (!w) return;

    // 创建提示控件
    QLabel* label = new QLabel(text, w);
    QFont f("新宋体", 18, QFont::Bold);
    label->setFont(f);
    label->setStyleSheet(
        "QLabel {"
        "background-color: #388e3c;"
        "border: 1px solid white;"
        "color: white;"
        "padding: 6px;"
        "border-radius: 6px;"
        "}"
        );

    label->setWindowFlags(Qt::FramelessWindowHint);
    label->adjustSize();  // 必须先调整大小

    // 计算居中位置（相对于父窗口）
    QPoint center = w->rect().center();
    QPoint pos = center - QPoint(label->width()/2, label->height()/2);
    label->move(pos);

    label->show();

    // 添加淡出动画
    QPropertyAnimation* anim = new QPropertyAnimation(label, "windowOpacity");
    anim->setDuration(1500);       // 动画总时长
    anim->setStartValue(1.0);      // 从完全可见开始
    anim->setEndValue(0.0);        // 最终透明
    anim->start(QAbstractAnimation::DeleteWhenStopped);

    // 自动销毁
    QTimer::singleShot(1500, label, &QLabel::deleteLater);
}
