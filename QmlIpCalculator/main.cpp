#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ipcalculator.h>
#include <QQmlContext>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<IpCalculator>("IpCalculator", 1, 0, "IpCalculator");//регистрация IpCalculator как тип QML
    const QUrl url(QStringLiteral("qrc:/QmlNetworkAnalyzer/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
