#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <view.h>
#include <paintball.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    qmlRegisterType<view>("Backend",1,0,"View");
    qmlRegisterType<paintball>("Paint",1,0,"Paintball");//needs to have the same name as the Paintball in Paintball.qml


    engine.loadFromModule("ThreeBody2", "Main");//when loading, needs to be registered


    return app.exec();
}
