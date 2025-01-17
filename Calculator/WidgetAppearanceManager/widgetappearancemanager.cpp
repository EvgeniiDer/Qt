#include "widgetappearancemanager.h"

WidgetAppearanceManager::WidgetAppearanceManager(QObject* parent) : QObject(parent),
    settings("NoCompany", "Calculator"){


}
void WidgetAppearanceManager::saveGeometry(const QWidget* widget, const QString& widgetName)
{
    if(!widget)
        return;

    settings.setValue(settingsKey(widgetName, "pos"), widget->pos());
    settings.setValue(settingsKey(widgetName, "size"), widget->size());

}
bool WidgetAppearanceManager::restoreGeometry(const QWidget* wodget, const QString& widgetName)
{

}

void WidgetAppearanceManager::saveFont(const QWidget& widget, const QString& widgetName)
{

}
bool WidgetAppearanceManager::restoreFont(const QWidget& widget, const QString& widgetName)
{

}

void WidgetAppearanceManager::saveStyle(const QWidget& widget, const QString& widgetName)
{

}
bool WidgetAppearanceManager::restoreStyle(const QWidget& widget, const QString& widgetName)
{

}
