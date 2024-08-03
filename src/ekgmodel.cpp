#include "ekgmodel.h"
#include <QRandomGenerator>

EKGModel::EKGModel(QObject *parent) : QObject(parent) {
    simulateData();
}

QVector<double> EKGModel::getData() const {
    return data;
}

void EKGModel::simulateData() {
    data.resize(1000);
    for (int i = 0; i < data.size(); ++i) {
        data[i] = QRandomGenerator::global()->bounded(1.0); // Simulate some data
    }
}
