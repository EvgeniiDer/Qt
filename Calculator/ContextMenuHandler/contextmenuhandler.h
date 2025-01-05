#ifndef CONTEXTMENUHANDLER_H
#define CONTEXTMENUHANDLER_H

#include <QObject>
#include <QMenu>
#include <QMessageBox>
#include <QFontDialog>
#include <QAction>
#include <QInputDialog>
#include <QPointer>

class MainWindow; // Предварительное определение класса

class ContextMenuHandler : public QObject
{
    Q_OBJECT
private:
    QPointer<MainWindow> mainWindow; // Используем QPointer для безопасного доступа
public:
    ContextMenuHandler(MainWindow* mainWindow);
    void showContexMenu(const QPoint& pos) const;
    void changeSkin();
    void changeFont();
};

#endif // CONTEXTMENUHANDLER_H
