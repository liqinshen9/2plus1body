#ifndef VIEW_H
#define VIEW_H
#include <QQmlApplicationEngine>
#include <QQmlContext> //needed to find engine
#include <QQuickItem>


class view:public QQuickItem
{
    Q_OBJECT
public:
    view(QQuickItem * parent = nullptr);
    Q_INVOKABLE void initialize();
private:
    QQmlApplicationEngine * engine = nullptr;
};

#endif // VIEW_H
