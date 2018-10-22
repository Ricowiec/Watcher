#ifndef WBUTTON_H
#define WBUTTON_H

#include <QObject>
#include <QtQuick/QQuickPaintedItem>
#include <QtQuick/QQuickItem>
#include <QColor>
#include <QPen>
#include <QPainter>
#include <QDebug>

class WButton : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ getColor WRITE setColor)
    Q_PROPERTY(QColor outlineColor READ getOutlineColor WRITE setOutlineColor)
    Q_PROPERTY(int outlineWidth READ getOutlineWidth WRITE setOutlineWidth)

public:
    WButton(QQuickItem *parent = nullptr);

    void setColor(const QColor &color) { m_color = color; update(); m_brush = QBrush(m_color); };
    void setOutlineColor(const QColor &outlineColor) { m_outlineColor = outlineColor; update(); m_pen = QPen(m_outlineColor); };
    void setOutlineWidth(const int &width) { m_outlineWidth = width; update(); };

    QColor getColor() const { return m_color; };
    QColor getOutlineColor() const { return m_outlineColor; };
    int getOutlineWidth() const { return m_outlineWidth; };

    void paint(QPainter *painter);

private:
    QColor m_color;
    QBrush m_brush;

    QColor m_outlineColor;
    int m_outlineWidth;
    QPen m_pen;
};

#endif // WBUTTON_H
