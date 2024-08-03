import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    width: 600
    height: 400

    // Create a QML object that wraps the QWT plot
    // This part assumes that QWT integration with QML is handled by C++
    // and a QML wrapper will be available for EKGPlot

    EKGPlot {
        id: plot
        anchors.fill: parent
        // Bind properties here
    }
}
