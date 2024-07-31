// ekgviewmodel.cpp
#include "ekgviewmodel.h"
#include <QDateTime>

EKGViewModel::EKGViewModel(QObject *parent)
    : QObject(parent), m_model(nullptr), m_heartRate(0.0)
{
}

EKGModel* EKGViewModel::model() const
{
    return m_model;
}

void EKGViewModel::setModel(EKGModel* model)
{
    if (m_model != model)
    {
        m_model = model;
        emit modelChanged();
        calculateHeartRate();
    }
}

double EKGViewModel::heartRate() const
{
    return m_heartRate;
}

void EKGViewModel::calculateHeartRate()
{
    if (!m_model)
        return;

    // Simple heart rate calculation based on EKG data
    // Assuming EKG data has peaks every second for simplicity
    int peakCount = 0;
    for (size_t i = 1; i < m_model->getData().size(); ++i)
    {
        if (m_model->getData()[i] > 0.8 && m_model->getData()[i-1] <= 0.8)
        {
            ++peakCount;
        }
    }

    m_heartRate = peakCount * 60.0 / 10; // Assuming 10 seconds of data
    emit heartRateChanged();
}
