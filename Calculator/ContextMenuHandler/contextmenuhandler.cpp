#include "contextmenuhandler.h"
#include "../mainwindow.h"
ContextMenuHandler::ContextMenuHandler(MainWindow* mainWindow) : mainWindow(mainWindow)
{

}
void ContextMenuHandler::showContexMenu(const QPoint& pos)const
{
    QMenu contextMenu(mainWindow);

    // Добавляем действия в контекстное меню
    QAction* changeSkinAction = contextMenu.addAction("Change skin");
    QAction* changeFontAction = contextMenu.addAction("Change font");

    // Подключаем действия к слотам
    connect(changeSkinAction, &QAction::triggered, this, &ContextMenuHandler::changeSkin);
    connect(changeFontAction, &QAction::triggered, this, &ContextMenuHandler::changeFont);

    contextMenu.addAction(changeSkinAction);
    contextMenu.addAction(changeFontAction);
    // Отображаем контекстное меню в позиции курсора
    contextMenu.exec(pos);
}

void ContextMenuHandler::changeSkin()
{
    //QMessageBox::information(mainWindow, "Select Skin", "There will be a choice of skins here");
    // Здесь можно реализовать логику выбора скина
    // Например, открытие диалогового окна с выбором скина
    QStringList skins = {"Light", "Dark", "Blue", "Green"};
    bool ok;
    QString selectedSkin = QInputDialog::getItem(mainWindow, "Select Skin", "Select Skin:", skins, 0, false, &ok);

    if (ok && !selectedSkin.isEmpty()) {
        // Применяем выбранный скин
        if (selectedSkin == "Light")
        {
            mainWindow->setStyleSheet("background-color: white; color: black;");
        } else if (selectedSkin == "Dark")
        {
            mainWindow->setStyleSheet("background-color: black; color: white;");
        } else if (selectedSkin == "Blue")
        {
            mainWindow->setStyleSheet("background-color: blue; color: white;");
        } else if (selectedSkin == "Green")
        {
            mainWindow->setStyleSheet("background-color: green; color: white;");
        }
    }
}
void ContextMenuHandler::changeFont()
{
    QMessageBox::information(mainWindow, "Select Font", "There will be a choice of font here");
}
