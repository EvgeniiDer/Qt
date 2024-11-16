#include "menubar.h"


MenuBar::MenuBar(const QString& strTitle, QWidget* parent) : QMenu(strTitle, parent)
{
    QAction* openAction = new QAction("Open", this);
    QAction* saveAction = new QAction("Save", this);
    QAction* closeAction = new QAction("Close", this);

    connect(openAction, &QAction::triggered, this, &MenuBar::openNewFile);
    connect(saveAction, &QAction::triggered, this, &MenuBar::saveFile);
    connect(closeAction, &QAction::triggered, this, &MenuBar::confermExit); // Исправлено: добавлена точка с запятой

    this->addAction(openAction);
    this->addAction(saveAction);
    this->addAction(closeAction);

}
///QTextsStream cout(stdout);

void MenuBar::openNewFile()
{
    QMessageBox::information(this, "Information", "Opening New File");
}
void MenuBar::saveFile()
{
    QMessageBox::information(this, "Information", "Save File");
}
void MenuBar::confermExit()
{
    QMessageBox::StandardButton reply;
    reply =QMessageBox::question(nullptr, "Confirmation", "Do u r want exit?",
                                  QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else{
        QMessageBox::information(this,"Nice", "Have a nice Day");
    }
}
