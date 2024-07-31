// Main.qml
import QtQuick 6.0
import QtQuick.Controls 6.0
import Qwt 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "EKG Simulation"

    EKGViewModel {
        id: viewModel
        model: ekgModel
    }

    EKGModel {
        id: ekgModel
    }

    QwtPlot {
        id: plot
        anchors.fill: parent
        title: "EKG Plot"
        legendVisible: true

        QwtPlotCurve {
            title: "EKG Signal"
            data: QwtData.fromModel(ekgModel)
            pen.color: "blue"
        }

        // Scroll and zoom functionality
        QwtPlotZoomer {
            canvas: plot.canvas
            zoomBase: 2.0
        }

        QwtPlotPanner {
            canvas: plot.canvas
        }

        // Heart rate display
        Text {
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Heart Rate: " + viewModel.heartRate.toFixed(2) + " BPM"
            font.pointSize: 16
        }
    }
}
