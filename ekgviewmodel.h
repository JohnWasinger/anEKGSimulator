// ekgviewmodel.h
#ifndef EKGVIEWMODEL_H
#define EKGVIEWMODEL_H

#include <QObject>
#include "ekgmodel.h"

class EKGViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(EKGModel* model READ model WRITE setModel NOTIFY modelChanged)
    Q_PROPERTY(double heartRate READ heartRate NOTIFY heartRateChanged)

public:
    explicit EKGViewModel(QObject *parent = nullptr);

    EKGModel* model() const;
    void setModel(EKGModel* model);

    double heartRate() const;

public slots:
    void calculateHeartRate();

signals:
    void modelChanged();
    void heartRateChanged();

private:
    EKGModel* m_model;
    double m_heartRate;
};

#endif // EKGVIEWMODEL_H
