#ifndef EKGPLOT_H
#define EKGPLOT_H

#include <QQuickPaintedItem>
#include <QPainter>
#include <QwtPlot>
#include <QwtPlotCurve>

class EKGPlot : public QQuickPaintedItem {
    Q_OBJECT

public:
    EKGPlot(QQuickItem *parent = nullptr);

    void paint(QPainter *painter) override;

private:
    QwtPlot *plot;
    QwtPlotCurve *curve;
};

#endif // EKGPLOT_H
