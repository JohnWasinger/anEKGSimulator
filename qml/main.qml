import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "EKG MVVM Example"

    EKGView {
        id: ekgView
        anchors.fill: parent
    }
}
