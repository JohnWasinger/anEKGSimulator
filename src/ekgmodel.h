#ifndef EKGMODEL_H
#define EKGMODEL_H

#include <QObject>
#include <QVector>

class EKGModel : public QObject {
    Q_OBJECT

public:
    explicit EKGModel(QObject *parent = nullptr);
    
    Q_INVOKABLE QVector<double> getData() const;

private:
    QVector<double> data;
    void simulateData();
};

#endif // EKGMODEL_H
