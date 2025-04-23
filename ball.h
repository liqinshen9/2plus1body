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
private:
    QQuickItem *paintball=nullptr;

};

#endif // BALL_H
