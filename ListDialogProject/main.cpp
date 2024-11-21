#include "head.h"
#include "MainWindow/mainwindow.h"
#include <QStyleFactory>
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    MainWindow* mainWindow = new MainWindow();
    mainWindow->show();
    app.exec();
}
