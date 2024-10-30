#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QWidget>
#include<QLayout>
#include<QLabel>
#include<QTextEdit>
#include<QFrame>

#include"../QCustomPushButtons/pushbutton.h"
#include"../QCustomMenuBar/menubar.h"

class MainWindow : public QMainWindow
{
private:
    MenuBar* menu;
    QLabel* infoLabel;
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
/*#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>

class MainWindow : public QMainWindow {
public:
    MainWindow() {
        // Создаем меню "Файл"
        QMenu *fileMenu = menuBar()->addMenu("Файл");

        // Создаем действия
        QAction *newAction = new QAction("Создать", this);
        QAction *exitAction = new QAction("Выход", this);

        // Подключаем действия к слотам
        connect(newAction, &QAction::triggered, this, &MainWindow::createNewFile);
        connect(exitAction, &QAction::triggered, this, &QApplication::quit);

        // Добавляем действия в меню
        fileMenu->addAction(newAction);
        fileMenu->addAction(exitAction);
    }

private slots:
    void createNewFile() {
        QMessageBox::information(this, "Информация", "Создание нового файла...");
    }
};*/

#endif // MAINWINDOW_H
