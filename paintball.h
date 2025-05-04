#ifndef PAINTBALL_H
#define PAINTBALL_H
#include <QQuickPaintedItem>
#include <QPainter>

class paintball: public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color WRITE setColor() READ getColor())
public:
    paintball(QQuickItem * parent = nullptr);
    void paint(QPainter * painter);

    QColor getColor(){return color;}
    void setColor(QColor col);
private:
    QColor color = Qt::black;
};


#endif // PAINTBALL_H
