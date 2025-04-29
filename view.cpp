#include "view.h"
#include <QtMath>
#include <QDebug>

view::view(QQuickItem * parent):
    QQuickItem(parent)
{
    timer.setInterval(17);
    connect(&timer, SIGNAL(timeout()),this,SLOT(iterate()));
    timer.start();

}


void view::initialize() {
    //finds application engine pointer
    engine = qobject_cast<QQmlApplicationEngine*>(QQmlEngine::contextForObject(this)->engine());
    for (int i = 0; i <2;i++) {
        objects.append(createball());

    }
    objects[0]->setPosition(QPointF(60,60));
    objects[0]->setVelocity(QVector2D(1,1));
    objects[1]->setPosition(QPointF(200,60));
    //objects[1]->setVelocity(QVector2D(3,4));
    //objects[2]->setPosition(QPointF(340,60));
    //objects[2]->setVelocity(QVector2D(0.5,0));

}

Ball* view::createball()
{
    Ball *ball  = new Ball();
    QQmlComponent component(engine, QUrl::fromLocalFile("ThreeBody2/Paintball.qml"));
    QQuickItem * object = qobject_cast<QQuickItem*>(component.create());
    object->setParentItem(this);
    object->setParent(engine);
    ball->setPaintball(object);
    return ball;

}

void view::iterate()//will run multiple times
{
    float resultx = qPow(objects[1]->position().x() - objects[0]->position().x(),2);
    float resulty = qPow(objects[1]->position().y() - objects[0]->position().y(),2);

    float resultx1 = qPow(objects[0]->position().x() - objects[1]->position().x(),2);
    float resulty1 = qPow(objects[0]->position().y() - objects[1]->position().y(),2);

    float distance = qSqrt(resultx+resulty);
    //qDebug()<< distance;
    QVector2D result;//object[0] to object[1]
    QVector2D result1;//object[1] to object[0]

    result.setX(objects[1]->position().x() - objects[0]->position().x());
    result.setY(objects[1]->position().y() - objects[0]->position().y());
    result1.setX(objects[0]->position().x() - objects[1]->position().x());
    result1.setY(objects[0]->position().y() - objects[1]->position().y());

    float length1 = qPow(result.x(),2);
    float length2 = qPow(result.y(),2);
    float length = qSqrt(length1+length2);
    //qDebug()<<result/length;
    if(distance<100){
        distance=100;
    }
    float force = 500 * 1/qPow(distance,2);
    QVector2D new_v = (result/distance) * force;//accleration
    objects[0]->setVelocity(objects[0]->getVelocity() + new_v);

    QVector2D new_v1 = (result1/distance) * force;//accleration
    objects[1]->setVelocity(objects[1]->getVelocity() + new_v1);


    for (int i =0;i<objects.length();i++) {

        QVector2D velocity = objects[i]->getVelocity();
        objects[i]->setPosition(objects[i]->position()+velocity.toPointF());
        //objects[i]->setVelocity(velocity+QVector2D(0,0.05));//acceleration gravity

        if (objects[i]->position().y() + 100 > height()){
            objects[i]->setPosition(QPointF(objects[i]->position().x(), height()-100));
            QVector2D v = objects[i]->getVelocity();
            QVector2D new_v = QVector2D(v.x(), v.y()*-0.9);
            objects[i]->setVelocity(new_v);
        }
        if (objects[i]->position().y() < 0){
            objects[i]->setPosition(QPointF(objects[i]->position().x(), 0));
            QVector2D v = objects[i]->getVelocity();
            QVector2D new_v = QVector2D(v.x(), v.y()*-0.9);
            objects[i]->setVelocity(new_v);
        }


        if (objects[i]->position().x()+100>width()) {
            objects[i]->setPosition(QPointF(width()-100, objects[i]->position().y()));
            QVector2D v = objects[i]->getVelocity();
            QVector2D new_v = QVector2D(v.x()*-0.9,v.y());
            objects[i]->setVelocity(new_v);
        }

        if (objects[i]->position().x() < 0){
            objects[i]->setPosition(QPointF(0,objects[i]->position().y()));
            QVector2D v = objects[i]->getVelocity();
            QVector2D new_v = QVector2D(v.x()*-0.9,v.y());
            objects[i]->setVelocity(new_v);

        }
    }
}













