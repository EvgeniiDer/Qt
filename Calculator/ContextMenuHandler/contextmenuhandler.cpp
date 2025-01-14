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
    // Пример, открытие диалогового окна с выбором скина
    QStringList skins = {"Light", "Dark", "Blue", "Green"};
    bool ok;
    QString selectedSkin = QInputDialog::getItem(mainWindow, "Select Skin", "Select Skin:", skins, 0, false, &ok);

    if (ok && !selectedSkin.isEmpty()) {
        // Применяем выбранный скин
        if (selectedSkin == "Light")
        {
            mainWindow->getCentralWgt()->setStyleSheet("background-color: white;"
                                                       "padding: 5px;"
                                                       "border: none;");
        } else if (selectedSkin == "Dark")
        {
            mainWindow->getCentralWgt()->setStyleSheet("background-color: black;"
                                                       "padding: 5px;"
                                                       "border: none;");
        } else if (selectedSkin == "Blue")
        {
            mainWindow->getCentralWgt()->setStyleSheet("background-color: blue;"
                                                       "padding: 5px;"
                                                       "border: none;");
        } else if (selectedSkin == "Green")
        {
            mainWindow->getCentralWgt()->setStyleSheet("background-color: green;"
                                                       "padding: 5px;"
                                                       "border: none;");
        }
    }
}
void ContextMenuHandler::changeFont()
{
    //QMessageBox::information(mainWindow, "Select Font", "There will be a choice of font here");
    bool ok;
    QFont font = QFontDialog::getFont(&ok, mainWindow->getCentralWgt()->font(), mainWindow);
    if(ok)
    {
        //Изменяет Шрифт главного виджета
        mainWindow->getCentralWgt()->setFont(font);

        //Ищем Экземпляры CalcultorButton
        QList<CalculatorButton*> listButtons = mainWindow->findChildren<CalculatorButton*>();

        //Прменяем шрифт ко всем Найденным экземлпярам класса CalculatorButton
        for(CalculatorButton* button: listButtons)
        {
            button->setFont(font);
        }
        //Ищем Экземпляры CalculatorLineEdit
        QList<CalculatorLineEdit*> lnEditFont = mainWindow->findChildren<CalculatorLineEdit*>();
        for(CalculatorLineEdit* ld: lnEditFont)
        {
            ld->setFont(font);
        }
        //Применяем шрифт ко всем Найденым экземплярам класса CalLabel
        QList<CalLabel*> cLabelFont = mainWindow->findChildren<CalLabel*>();
        for(CalLabel* lb: cLabelFont)
        {
            lb->setFont(font);
        }
    }
}
