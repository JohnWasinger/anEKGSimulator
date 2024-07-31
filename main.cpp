// main.cpp
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ekgmodel.h"
#include "ekgviewmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    EKGModel model;
    EKGViewModel viewModel;

    viewModel.setModel(&model);

    engine.rootContext()->setContextProperty("viewModel", &viewModel);
    engine.rootContext()->setContextProperty("ekgModel", &model);

    engine.load(QUrl(QStringLiteral("qrc:/Main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
