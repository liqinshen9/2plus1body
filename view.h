#ifndef VIEW_H
#define VIEW_H

#include <Ball.h>
#include <QQmlApplicationEngine>
#include <QQmlContext> //needed to find engine
#include <QQuickItem>


class view: public QQuickItem
{
    Q_OBJECT
public:
    view(QQuickItem * parent = nullptr);
    Q_INVOKABLE void initialize();
    Ball * createball();
private:
    QQmlApplicationEngine * engine = nullptr;
    QVector<Ball*> objects;
};

#endif // VIEW_H
