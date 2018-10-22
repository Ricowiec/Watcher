#include "wbutton.h"

WButton::WButton(QQuickItem *parent)
//    : QQuickPaintedItem (parent)
{
    if(parent)
    {
        this->setWidth(parent->width());
//        qDebug() << "in if";

    }
//    qDebug() << "End of constr";
}

void WButton::paint(QPainter *painter)
{
    m_pen.setWidth(m_outlineWidth);
    painter->setPen(m_pen);
    painter->setBrush(m_brush);

    painter->setRenderHints(QPainter::Antialiasing, true);

    QRectF rect;
    rect.setWidth(this->width());
    rect.setHeight(this->height());
    rect.setX(this->x());
    rect.setY(this->y());

    painter->drawRect(rect);
}
