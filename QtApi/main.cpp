#include"head.h"


QTextStream cout(stdout);
int main(int argc, char *argv[])
{
    cout << "Hellow Qt" << Qt::endl;
    QCoreApplication a(argc, argv);

    return a.exec();
}
