#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QTime>
#include <QHBoxLayout>
#include <QSettings>
#include <QFontDatabase>
#include "alarmswindow.h"

class AlarmsWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    //Q_PROPERTY(bool topmost READ isTopmost WRITE setTopmost)
    //Q_PROPERTY(bool showControls READ isShowControls WRITE setShowControls)

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    bool isTopmost() const;
    bool isShowControls() const;

    void setTopmost(bool topmost);
    void setShowControls(bool controls);

signals:
    void controlsVisibilityChanged(bool visible);

private slots:
    void updateTime();
    void onTopmostAction();
    void onControlsAction();
    void showAlarmWindow();
    void loadSettings();
    void saveSettings();

private:
    QMenu *trayMenu;
    QSystemTrayIcon *trayIcon;
    QTimer *timer;
    QLabel *timeLabel;
    QLabel *controlsLabel;
    AlarmsWindow *alarmsWindow;
    bool topmost;
    bool showControls;
    QWidget *centralWidget;
    QHBoxLayout *mainLayout;
    QSettings settings;
    bool dragging;
    QPoint mousePressPosition;
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;


};
#endif // MAINWINDOW_H
