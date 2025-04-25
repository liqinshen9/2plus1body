#include "view.h"

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
    for (int i = 0; i <3;i++) {
        objects.append(createball());
        break;

    }
    objects[0]->setPosition(QPointF(60,60));
    objects[0]->setVelocity(QVector2D(5,0));
    //objects[1]->setPosition(QPointF(200,60));
    //objects[1]->setVelocity(QVector2D(5,0));
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

void view::iterate()
{
    for (int i =0;i<objects.length();i++) {
        QVector2D velocity = objects[i]->getVelocity();
        objects[i]->setPosition(objects[i]->position()+velocity.toPointF());
        objects[i]->setVelocity(velocity+QVector2D(0,0.05));//acceleration

        if (objects[i]->position().y() + 100 > height() || objects[i]->position().x() + 100 > width()) {
            objects[i]->setPosition(QPointF(width()-100, objects[i]->position().y()));
            qDebug()<<222222222222222;
            //objects[i]->setPosition(QPointF(objects[i]->position().x(), height()-100));

            //objects[i]->setVelocity(objects[i]->getVelocity()*-0.9);
        }
    }
}













