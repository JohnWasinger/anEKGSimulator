#include "ekgplot.h"

EKGPlot::EKGPlot(QQuickItem *parent) : QQuickPaintedItem(parent), plot(new QwtPlot()), curve(new QwtPlotCurve()) {
    plot->setTitle("EKG Plot");
    plot->setCanvasBackground(Qt::white);

    QVector<double> xData(1000);
    QVector<double> yData(1000);

    for (int i = 0; i < 1000; ++i) {
        xData[i] = i;
        yData[i] = qSin(i / 10.0); // Simple sine wave for demonstration
    }

    curve->setSamples(xData, yData);
    curve->attach(plot);

    plot->replot();
}

void EKGPlot::paint(QPainter *painter) {
    plot->render(painter);
}
