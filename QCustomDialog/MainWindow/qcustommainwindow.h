#ifndef QCUSTOMMAINWINDOW_H
#define QCUSTOMMAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QDebug>
#include <QInputDialog>
#include <QTextCursor>
#include <QTextBlock>
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPushButton* bttnOk;
    QPushButton* bttnDeleteLine;
    QPushButton* bttnAdd;
    QPushButton* bttnRem;
    QPushButton* bttnCancel;
    QPushButton* bttnAddNewLine;
    QTextEdit* txtEditLeft;
    QTextEdit* txtEditRight;
    QWidget* centralWidget;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void removeEmptyLines(QTextEdit *textEdit);
    void removeLine(QTextEdit *textEdit);

signals:
public slots:
    void onCloseButtonSlot();
    void onOkButtonSlot();
    void onAddNewLineSlot();
    void onAddFromLeftToRightSlot();
    void onRemoveFromRightToLeftSlot();
    void onDeleteFromLeftSlot();

};

#endif // MAINWINDOW_H
