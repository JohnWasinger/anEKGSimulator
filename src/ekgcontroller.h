#ifndef EKGCONTROLLER_H
#define EKGCONTROLLER_H

#include <QObject>
#include "ekgmodel.h"

class EKGController : public QObject {
    Q_OBJECT

public:
    explicit EKGController(QObject *parent = nullptr);

public slots:
    void zoomIn();
    void zoomOut();

private:
    EKGModel model;
};

#endif // EKGCONTROLLER_H
