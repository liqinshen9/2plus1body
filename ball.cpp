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
