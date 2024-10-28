#include"head.h"
#include"./QCustomMainWindow/mainwindow.h"

QTextStream cout(stdout);

int main(int argc, char* argv[])
{
    QApplication apl(argc, argv);
    MainWindow *mainWin = new MainWindow();
    mainWin->show();
    apl.exec();
}
