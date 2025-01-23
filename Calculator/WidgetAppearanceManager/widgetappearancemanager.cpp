#include "widgetappearancemanager.h"

WidgetAppearanceManager::WidgetAppearanceManager(QObject* parent) : QObject(parent),
    settings("NoCompany", "Calculator"){


}
QString WidgetAppearanceManager::settingsKey(const QString& widgetName, const QString& parameter)
{
    return widgetName + "/" + parameter;
}

void WidgetAppearanceManager::saveGeometry(const QWidget* widget, const QString& widgetName)
{
    if(!widget)
        return;

    settings.setValue(settingsKey(widgetName, "pos"), widget->pos());
    settings.setValue(settingsKey(widgetName, "size"), widget->size());

}
bool WidgetAppearanceManager::restoreGeometry(QWidget* widget, const QString& widgetName)
{
    if(!widget)
        return false;
    QPoint pos = settings.value(settingsKey(widgetName, "pos")).toPoint();
    QSize size = settings.value(settingsKey(widgetName, "size")).toSize();

    if(!pos.isNull() && !size.isNull())
    {
        widget->move(pos);
        widget->resize(size);
        return true;
    }
    else{
        return false;
    }
}

void WidgetAppearanceManager::saveFont(const QWidget* widget, const QString& widgetName)
{
    if(!widget)
        return;
    settings.setValue(settingsKey(widgetName, "font"), widget->font());
}
bool WidgetAppearanceManager::restoreFont(QWidget* widget, const QString& widgetName)
{
    if(!widget)
        return false;
    QFont font = settings.value(settingsKey(widgetName, "font"), QFont()).value<QFont>();//как я понял извлекаем безопасно шрифет
    if(font != QFont())//проверка на пустой шрифт
    {
        widget->setFont(font);
        return true;
    }
    else
    {
        return false;
    }
}

void WidgetAppearanceManager::saveStyleSheet(const QWidget* widget, const QString& widgetName)
{
    if(!widget)
        return;
    settings.setValue(settingsKey(widgetName, "styleSheet"), widget->styleSheet());
}
bool WidgetAppearanceManager::restoreStyleSheet(QWidget* widget, const QString& widgetName)
{
    if(!widget)
        return false;
    QString styleSheet = settings.value(settingsKey(widgetName, "styleSheet"), QString()).toString();
    if(!styleSheet.isNull())
    {
        widget->setStyleSheet(styleSheet);
    }
}
