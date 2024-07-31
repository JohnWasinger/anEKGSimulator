// ekgmodel.cpp
#include "ekgmodel.h"
#include <QRandomGenerator>

EKGModel::EKGModel(QObject *parent)
    : QAbstractListModel(parent)
{
    generateData(1000); // Generate initial data
}

int EKGModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.size();
}

QVariant EKGModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_data.size())
        return QVariant();

    if (role == ValueRole)
        return m_data[index.row()];

    return QVariant();
}

QHash<int, QByteArray> EKGModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ValueRole] = "value";
    return roles;
}

void EKGModel::generateData(int points)
{
    m_data.clear();
    m_data.reserve(points);
    auto rng = QRandomGenerator::global();
    for (int i = 0; i < points; ++i)
    {
        m_data.push_back(rng->bounded(0.0, 1.0));
    }
    emit dataChanged(index(0), index(m_data.size() - 1));
}

const std::vector<double>& EKGModel::getData() const
{
    return m_data;
}
