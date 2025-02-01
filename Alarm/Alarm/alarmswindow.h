#ifndef ALARMSWINDOW_H
#define ALARMSWINDOW_H

#include <QDIalog>
#include <QListWidget>
#include <QPushButton>

#include <QTime>
#include <QMessageBox>
#include <QSettings>
#include <QTimer>
#include "timelineedit.h"

#include <QMediaPlayer>
#include <QAudioOutput>


class AlarmsWindow : public QDialog
{
    Q_OBJECT
public:
    AlarmsWindow(QWidget* parent = nullptr);

    ~AlarmsWindow()override;
    void checkAlarm(QTime currentTime);
    void loadAlarms();
    void saveAlarms();
private slots:
    void removeAlarm();
    void editAlarm();

    //void alarmTriggered(const QString& alarmTime);
    //void timeChanged(const QTime &time);
    void addAlarm(const AlarmData& alarm);

private:
    TimeLineEdit* timeLineEdit;

    QPushButton* removeButton;
    QPushButton* editButton;
    QPushButton* exitButton;
    QTimer* alarmTimer;

    QList<AlarmData> alarmDataList;
    QListWidget *alarmListWidget;


    void updateAlarmList();
    //bool isAlarmToday(const AlarmData& alarm);

    QMediaPlayer* player;
    QAudioOutput* audioOutput;
    //void closeEvent(QCloseEvent* event) override;

};

#endif // ALARMSWINDOW_H
