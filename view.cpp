#include "view.h"

view::view(QQuickItem * parent):
    QQuickItem(parent)
{

}


void view::initialize() {
    //finds application engine pointer
    engine = qobject_cast<QQmlApplicationEngine*>(QQmlEngine::contextForObject(this)->engine());
    for (int i = 0; i <3;i++) {
        objects.append(createball());
    }
    //objects[0]->setPosition(QPointF(60,60));
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
