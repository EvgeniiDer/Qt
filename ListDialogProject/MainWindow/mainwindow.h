#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../ListViewDelegate/listviewdelegate.h"
#include <QMainWindow>
#include <QlistWidget>
#include <QPushButton>
#include <QListWidget>
#include <QListView>
#include <QString>
#include <QStringListModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QKeyEvent>
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QWidget* centralWidget;
    QPushButton* btnOk;
    QPushButton* btnAdd;
    QPushButton* btnRem;
    QPushButton* btnCancel;
    //QListWidget* lstWidget;
    QStringList* strList;
    QListView* lstView;
    QStringListModel* strListModel;
    ListViewDelegate* viewDlg;


public:
    MainWindow(QWidget* parent = nullptr);
    void keyPressEvent(QKeyEvent* event);
private slots:
    void onCancelBtnSlot();
    void onOkBtnSlot();
    void onAddBtnSlot();
    void onRemBtnSlot();
};

#endif // MAINWINDOW_H
