#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
#include <QApplication>
#include <QWidget>
#include <QMenu>
#include <QContextMenuEvent>
#include <QMessageBox>

class CustomWidget : public QWidget {
    Q_OBJECT

public:
    CustomWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(400, 300); // Устанавливаем размер виджета
    }

protected:
    void contextMenuEvent(QContextMenuEvent *event) override {
        QMenu menu(this);
        QAction *settingsAction = menu.addAction("Настройки");
        connect(settingsAction, &QAction::triggered, this, &CustomWidget::showSettings);
        menu.exec(event->globalPos()); // Показываем меню в позиции курсора
    }

private slots:
    void showSettings() {
        QMessageBox::information(this, "Настройки", "Открыты настройки.");
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CustomWidget widget; // Создаем экземпляр нашего виджета
    widget.show(); // Показываем виджет
    return app.exec(); // Запускаем главный цикл приложения
}
