#ifndef BALL_H
#define BALL_H
#include <QQuickItem>

class Ball
{
public:
    Ball();
    void setVelocity(QVector2D v){
        velocity = v;
    }
    QVector2D getVelocity(){
        return velocity;
    }
    void setPaintball(QQuickItem *object) {
        paintball=object;
    }
    QQuickItem * getPaintball(){return paintball;}
    void setPosition(QPointF position);
    QPointF position();
    int getId();
    void setId(int otherId);
private:
    int Id = 0;
    QQuickItem *paintball=nullptr;
    QVector2D velocity;

};

#endif // BALL_H
