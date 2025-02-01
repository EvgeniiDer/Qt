#include "mainwindow.h"
#include "alarmswindow.h"
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QTime>
#include <QLabel>
#include <QTimer>
#include <QHBoxLayout>
#include <QSettings>
#include <QFontDatabase>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    settings("MyCompany", "ClockApp")
{
    this->setAttribute(Qt::WA_TranslucentBackground);
    //this->setWindowFlag(Qt::FramelessWindowHint);

    topmost = false;
    showControls = false;

    centralWidget = new QWidget(this);
    mainLayout = new QHBoxLayout(centralWidget);

    trayMenu = new QMenu(this);
    QAction *topmostAction = new QAction("Topmost", this);
    topmostAction->setCheckable(true);

    QObject::connect(topmostAction, &QAction::triggered, this, &MainWindow::onTopmostAction);
    trayMenu->addAction(topmostAction);

    QAction *controlAction = new QAction("Show Controls", this);
    controlAction->setCheckable(true);

    QObject::connect(controlAction, &QAction::triggered, this, &MainWindow::onControlsAction);
    trayMenu->addAction(controlAction);

    QAction *alarmAction = new QAction("Alarms",this);
    QObject::connect(alarmAction, &QAction::triggered, this, &MainWindow::showAlarmWindow);
    trayMenu->addAction(alarmAction);

    alarmsWindow = new AlarmsWindow(this);
    QAction *exitAction = new QAction("Exit", this);
    QObject::connect(exitAction, &QAction::triggered, this, &MainWindow::close);
    trayMenu->addAction(exitAction);

    //Проблема в том что QSystemTrayIcon создает эконку в системном трее
    //Видна буде с Права в верху а не с лева в верху перепутал с панелью настроек!!
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayMenu);
    trayIcon->setIcon(QIcon("/Users/evgenii/Project/Qt/Alarm/Alarm/Icons/icon.png"));
    trayIcon->show();

    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(1000);

    timeLabel = new QLabel(this);
    timeLabel->setStyleSheet("font-size: 30px; color: white;");
    int fontId = QFontDatabase::addApplicationFont("/Users/evgenii/Project/Qt/Alarm/Alarm/Source/font.ttf");
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font(fontFamily);
    timeLabel->setFont(font);

    updateTime();

    controlsLabel = new QLabel(this);
    controlsLabel->setStyleSheet("font-size: 10px; color: white;");
    controlsLabel->setText("Controls: OFF");




    mainLayout->addWidget(timeLabel);
    mainLayout->addWidget(controlsLabel);


    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
    //this->setDoubleBuffered(true); По Умолчанию двойная буферизация применяеться автоматически
    loadSettings();
}

MainWindow::~MainWindow()
{
    saveSettings();
}
bool MainWindow::isTopmost() const {
    return topmost;
}
bool MainWindow::isShowControls() const {
    return showControls;
}
void MainWindow::updateTime()
{
    QTime time = QTime::currentTime();
    QString timeString = time.toString("hh:mm:ss");
    timeLabel->setText(timeString);
    alarmsWindow->checkAlarm(time);
}

void MainWindow::setShowControls(bool controls)
{
    this->showControls = controls;
    emit controlsVisibilityChanged(controls);
    if (controls)
        alarmsWindow->show();
    else
        alarmsWindow->hide();
}
void MainWindow::onControlsAction()
{
    showControls = !showControls;
    setShowControls(showControls);
    if(showControls)
        controlsLabel->setText("Controls: ON");
    else
        controlsLabel->setText("Controls: OFF");

    qDebug() << "Controls was changed: " << showControls;
}

void MainWindow::setTopmost(bool topmost)
{
    this->topmost = topmost;
    if(this->topmost)
    {
        this->setWindowFlag(Qt::WindowStaysOnTopHint);
        this->show();
    }
    else
    {
        this->setWindowFlag(Qt::WindowStaysOnTopHint, false);
        this->show();
    }
}

void MainWindow::onTopmostAction()
{
    topmost = !topmost;
    setTopmost(topmost);
    qDebug() << "Topmost Changed";
}

void MainWindow::showAlarmWindow()
{

    alarmsWindow->show();
}

void MainWindow::loadSettings()
{
    topmost = settings.value("topmost", false).toBool();
    showControls = settings.value("showControls", false).toBool();
    setTopmost(topmost);
    setShowControls(showControls);

    int mainWindowX = settings.value("mainWindowX", 100).toInt();
    int mainWindowY = settings.value("mainWindowY", 100).toInt();
    move(mainWindowX, mainWindowY);
}
void MainWindow::saveSettings()
{
    settings.setValue("topmost", topmost);
    settings.setValue("showControls", showControls);

    settings.setValue("mainWindowX", this->x());
    settings.setValue("mainWindowY", this->y());
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
}
