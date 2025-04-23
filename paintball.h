#ifndef PAINTBALL_H
#define PAINTBALL_H
#include <QQuickPaintedItem>
#include <QPainter>

class paintball: public QQuickPaintedItem
{
    Q_OBJECT
public:
    paintball(QQuickItem * parent = nullptr);
    void paint(QPainter * painter);
};

#endif // PAINTBALL_H
