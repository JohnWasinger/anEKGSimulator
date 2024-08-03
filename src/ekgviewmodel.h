#ifndef EKGVIEWMODEL_H
#define EKGVIEWMODEL_H

#include <QObject>
#include "ekgmodel.h"

class EKGViewModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QVector<double> data READ data NOTIFY dataChanged)

public:
    explicit EKGViewModel(QObject *parent = nullptr);

    QVector<double> data() const;

signals:
    void dataChanged();

private:
    EKGModel model;
};

#endif // EKGVIEWMODEL_H
