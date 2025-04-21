#include "view.h"

view::view(QQuickItem * parent):
    QQuickItem(parent)
{

}


void view::initialize() {
    //finds application engine pointer
    engine = qobject_cast<QQmlApplicationEngine*>(QQmlEngine::contextForObject(this)->engine());
}
