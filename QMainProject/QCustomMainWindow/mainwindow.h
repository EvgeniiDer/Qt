#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QWidget>
#include<QLayout>
#include<QLabel>
#include<QTextEdit>
#include"../QCustomPushButtons/pushbutton.h"
class MainWindow : public QMainWindow
{
private:
    QTextEdit* textEdit;
    PushButton* buttonOk;
    PushButton* buttonCancel;
    QString titleName;
    int winW;
    int winH;
    QWidget *centralWidget;
    void setupCentralWidget();
    void setupMainWindow(const QString& _titleName = "Title by default", const int& _winW = 200,const int& _winH = 200);
public:
    MainWindow();
    MainWindow(const QString& _titleName);
    MainWindow(const QString& _titleName, int _winW, int _winH);
};

#endif // MAINWINDOW_H
