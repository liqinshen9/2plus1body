import QtQuick
import Backend 1.0
import Paint 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    View {
        id:root;
        width:parent.width;
        height:parent.height;
        Component.onCompleted: {
            initialize()
        }
    }
}
