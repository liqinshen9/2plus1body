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

void view::collision(Ball * b1, Ball * b2) {
    QPointF p1 = b1->position();
    QPointF p2 = b2->position();
    QPointF collision_vector = p2 - p1;

    QVector2D v = QVector2D(collision_vector);
    QVector2D vector = v.normalized();
    vector.normalize();

    double v1 = QVector2D::dotProduct(b1->getVelocity(),vector);
    double v2 = QVector2D::dotProduct(b2->getVelocity(),vector);
    double v1_final = v2;
    double v2_final = v1;
    qDebug()<<v1<<v2;
    QVector2D b1_newVelocity = vector * v1_final;
    QVector2D b2_newVelocity = vector * v2_final;
    qDebug()<<v1*vector<<b1_newVelocity<<b1->getVelocity();
    b1->setVelocity(b1->getVelocity() - v1*vector + b1_newVelocity);
    b2->setVelocity(b2->getVelocity() - v2*vector + b2_newVelocity);
    float diff = (100-v.length()) / 2;
    b1->setPosition(b1->position() + -1*diff*vector.toPointF());
    b2->setPosition(b2->position() + diff * vector.toPointF());
}

void view::initialize() {
    //finds application engine pointer
    engine = qobject_cast<QQmlApplicationEngine*>(QQmlEngine::contextForObject(this)->engine());
    int n = 5;
    for (int i = 0; i <n;i++) {
        objects.append(createball());
        objects[i]->setPosition(QPointF(i * 600 / n, i * 500 / n + 50));
        objects[i]->setId(i);
    }
    objects[0]->setVelocity(QVector2D(2,2));
    objects[1]->setVelocity(QVector2D(-4,0));
    //objects[0]->setPosition(QPointF(60,60));
    //objects[0]->setVelocity(QVector2D(1,1));
    //objects[1]->setPosition(QPointF(200,60));
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

QVector2D view::acceleration(Ball * b0, Ball * b1)
{
    QPointF p0 = b0->position();
    QPointF p1 = b1->position();
    float result = qPow(p1.x() - p0.x(),2)+ qPow(p1.y() - p0.y(),2);
    float distance = qSqrt(result);

    QVector2D v01;//object[0] to object[1]

    v01.setX(p1.x() - p0.x());
    v01.setY(p1.y() - p0.y());

    if(distance<100){
        distance=100;
    }

    float force = 500 * 1/qPow(distance,2);

    QVector2D a = (v01/distance) * force;//accleration

    return a;
}


void view::iterate()//will run multiple times
{

    int n = objects.size();
    for (int i = 0; i < n; i++) {
        QColor i_color = Qt::black;
        QColor j_color = Qt::black;
        for (int j = 0; j <n ;j++) {
            if (i!=j) {
                //QVector2D a = acceleration(objects[i],objects[j]);
                //objects[i]->setVelocity(objects[i]->getVelocity() + a);
                if(QVector2D(objects[i]->position()-objects[j]->position()).length() < 100){
                    i_color = Qt::red;
                    j_color = Qt::red;
                    collision(objects[i], objects[j]);
                }
                objects[i]->getPaintball()->setProperty("color",i_color);
                objects[j]->getPaintball()->setProperty("color",j_color);


            } else {
                continue;
            }
        }


    }
    //QPointF p = objects[i]->position();
    //Ball * b = objects[i];
    //QColor b0_color = Qt::black;
    //QColor b1_color = Qt::black;
    //QColor b2_color = Qt::black;
    //Ball * b1 = objects[1];:black;
    //QPointF p1 = objects[1]->position();
    //QPointF p0 = objects[0]->position();
    //QPointF p2 = objects[2]->position();
    //Ball * b1 = objects[1];
    //Ball * b0 = objects[0];
    //Ball * b2 = objects[2];

    //if(QVector2D(p1-p0).length() < 100){
        //b0_color = Qt::blue;
        //b1_color = Qt::blue;
    //}
    //b0->getPaintball()->setProperty("color",b0_color);
    //b1->getPaintball()->setProperty("color",b1_color);

    //if(QVector2D(p2-p0).length() < 100){
        //b0_color = Qt::blue;
        //b2_color = Qt::blue;
    //}
    //b2->getPaintball()->setProperty("color",b2_color);
    //b0->getPaintball()->setProperty("color",b0_color);
    //if(QVector2D(p2-p1).length() < 100){
        //b1_color = Qt::blue;
        //b2_color = Qt::blue;
    //}
    //b2->getPaintball()->setProperty("color",b2_color);
    //b1->getPaintball()->setProperty("color",b1_color);

    //QVector2D a01 = acceleration(b0,b1);
    //QVector2D a10 = acceleration(b1,b0);
    //QVector2D a02 = acceleration(b0,b2);
    //QVector2D a12 = acceleration(b1,b2);
    //QVector2D a20 = acceleration(b2,b0);
    //QVector2D a21 = acceleration(b2,b1);

    //b0->setVelocity(b0->getVelocity() + a01+a02);//Other is b1, this is b0
    //b1->setVelocity(b1->getVelocity() + a12+a10);
    //b2->setVelocity(b2->getVelocity() + a20+a21);



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













