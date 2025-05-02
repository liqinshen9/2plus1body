#ifndef VIEW_H
#define VIEW_H
#include <QTimer>
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
    QVector2D acceleration(Ball * b0, Ball * b1);
private:
    int count = 0;
    QTimer timer;

    QQmlApplicationEngine * engine = nullptr;
    QVector<Ball*> objects;

public slots:
    void iterate();
};

#endif // VIEW_H
