#include "mainwindow.h"

MainWindow::MainWindow() {
    this->setupMainWindow();
    this->setupCentralWidget();
}
MainWindow::MainWindow(const QString& _titleName) : titleName(_titleName)
{
    this->setupMainWindow(_titleName);
    this->setupCentralWidget();
}
MainWindow::MainWindow(const QString& _titleName , int _winW, int _winH)
    : titleName(_titleName),
      winW(_winW), winH(_winH)
{
    this->setupMainWindow(_titleName, _winW, _winH);
    this->setupCentralWidget();
}
void MainWindow::setupCentralWidget()
{
    centralWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->addWidget(new QLabel("Hellow Main Window", centralWidget));
    this->setCentralWidget(centralWidget);
}
void MainWindow::setupMainWindow(const QString& _titleName,const int& _winW, const int& _winH )
{
    titleName = _titleName,
    winW = _winW;
    winH = _winH;
    this->setWindowTitle(titleName);
    this->resize(winW, winH);
}
