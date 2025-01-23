#ifndef WIDGETAPPEARANCEMANAGER_H
#define WIDGETAPPEARANCEMANAGER_H

#include <QSettings>
#include <QObject>
#include <QWidget>

class WidgetAppearanceManager : public QObject
{
    Q_OBJECT
public:
    explicit WidgetAppearanceManager(QObject* parent = nullptr);

    void saveGeometry(const QWidget* widget, const QString& widgetName);
    bool restoreGeometry(QWidget* widget, const QString& widgetName);

    void saveFont(const QWidget* widget, const QString& widgetName);
    bool restoreFont(QWidget* widget, const QString& widgetName);

    void saveStyleSheet(const QWidget* widget, const QString& widgetName);
    bool restoreStyleSheet(QWidget* widget, const QString& widgetName);
private:
    QString settingsKey(const QString& widgetName, const QString& parameter);
    QSettings settings;
};

#endif // WIDGETAPPEARANCEMANAGER_H
