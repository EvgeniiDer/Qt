#include "mainwindow.h"
#include "./ui_mainwindow.h"
///Users/evgenii/Project/Qt/DynamicWindow/DynamicWindow/CursorAnim/cursor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->resize(600, 660);
    //QCursor cursor(QPixmap("../Qt/DynamicWindow/DynamicWindow/CursorAnim/cur1162.ani"));
    //this->setCursor(cursor);
    centerWindow();
    setWindowTitle("Size and position screen");
    QLabel* label = new QLabel(this);
    label->setAlignment(Qt::AlignHCenter);
    setCentralWidget(label);

\
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    updateTitle();
}
void MainWindow::moveEvent(QMoveEvent* event)
{
    QMainWindow::moveEvent(event);
    updateTitle();
}
void MainWindow::updateTitle()
{
    QSize size = this->size();
    QPoint pos = this->pos();
    setWindowTitle(QString("Размер: %1x%2, Положение: (%3, %4)")
                       .arg(size.width()).arg(size.height())
                       .arg(pos.x()).arg(pos.y()));
}

void MainWindow::centerWindow()
{
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int width = screenGeometry.width() * 0.75;
    int height = screenGeometry.height() * 0.75;
    setGeometry((screenGeometry.width() - width) / 2,
                (screenGeometry.height() - height) / 2,
                width, height);

}
