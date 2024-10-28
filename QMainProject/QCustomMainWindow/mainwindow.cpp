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
    buttonOk = new PushButton("Ok", 100, 500);
    buttonCancel = new PushButton("Cancel");
    QVBoxLayout* vLayout = new QVBoxLayout(centralWidget);
    vLayout->addWidget(new QLabel("Hellow Main Window it's Laybel", centralWidget));
    vLayout->addWidget(new QTextEdit("QTextEdit"));
    QHBoxLayout* hLayout = new QHBoxLayout();
    hLayout->addWidget(buttonOk);
    hLayout->addWidget(buttonCancel);
    vLayout->addLayout(hLayout);

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
