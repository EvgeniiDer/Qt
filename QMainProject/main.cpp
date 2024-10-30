#include"head.h"
#include"./QCustomMainWindow/mainwindow.h"

QTextStream cout(stdout);

int main(int argc, char* argv[])
{
    QApplication apl(argc, argv);
    MainWindow *mainWin = new MainWindow("Temp", 456, 234);
    mainWin->show();

    apl.exec();
}
/*#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include "QCustomMainWindow/mainwindow.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.resize(400, 300);
    window.show();
    return app.exec();
}*/





