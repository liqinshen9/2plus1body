#include "paintball.h"

paintball::paintball(QQuickItem * parent):
    QQuickPaintedItem(parent)
{

}

void paintball::paint(QPainter * painter)
{
    QPen pen;
    pen.setWidth(1);
    pen.setColor(color);

    painter->setBrush(Qt::NoBrush);
    painter->setPen(pen);
    painter->drawEllipse(0,0,width()-1,height()-1);
}

void paintball::setColor(QColor col)
{
    if(col == color){return;}
    color = col;
    update();
}
