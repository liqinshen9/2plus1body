#include "ball.h"

//needs to define reference to "Ball::setPosition(QPointF)"
Ball::Ball() {}

void Ball::setPosition(QPointF position)
{
    paintball->setPosition(position);
}

QPointF Ball::position()
{
    return paintball->position();
}

int Ball::getId()
{
    return Id;
}

void Ball::setId(int otherId)
{
    Id = otherId;
}

float Ball::getMass()
{
    return Mass;
}

void Ball::setMass(float otherMass)
{
    Mass = otherMass;
}

float Ball::getRadius()
{
    return radius;
}

void Ball::setRadius(float otherRadius)
{
    radius = otherRadius;
    paintball->setWidth(radius*2);
    paintball->setHeight(radius*2);
}

