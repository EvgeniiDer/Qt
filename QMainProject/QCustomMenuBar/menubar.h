#ifndef MENUBAR_H
#define MENUBAR_H

#include<QMenuBar>

#include<QAction>
#include<QMessageBox>
#include<QMenuBar>
#include<QMenu>
#include<QApplication>
class MenuBar : public QMenu
{
    Q_OBJECT
public:
    MenuBar(const QString& strTitle, QWidget* parent = nullptr);

private slots:
    void openNewFile();
    void saveFile();
    void confermExit();



};

#endif // MENUBAR_H
////////////
