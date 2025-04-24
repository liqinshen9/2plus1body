#ifndef BALL_H
#define BALL_H
#include <QQuickItem>

class Ball
{
public:
    Ball();
    void setPaintball(QQuickItem *object) {
        paintball=object;
    }
    void setPosition(QPointF position);
    QPointF position();
private:
    QQuickItem *paintball=nullptr;

};

#endif // BALL_H
