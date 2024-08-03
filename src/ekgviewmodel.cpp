#include "ekgviewmodel.h"

EKGViewModel::EKGViewModel(QObject *parent) : QObject(parent), model() {
}

QVector<double> EKGViewModel::data() const {
    return model.getData();
}
