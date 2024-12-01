#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCursor>
#include <QPixmap>
#include <QScreen>
#include <QGuiApplication>
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void centerWindow();
protected:
    void resizeEvent(QResizeEvent* event);
    void moveEvent(QMoveEvent* event);
private slots:
    void updateTitle();

};
#endif // MAINWINDOW_H
