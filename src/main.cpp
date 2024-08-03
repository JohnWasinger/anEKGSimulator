#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ekgviewmodel.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    EKGViewModel viewModel;

    engine.rootContext()->setContextProperty("ekgViewModel", &viewModel);
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
