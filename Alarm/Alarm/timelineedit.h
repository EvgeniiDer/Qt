#ifndef TIMELINEEDIT_H
#define TIMELINEEDIT_H

#include<QLineEdit>
#include <QTime>
#include<QTimeEdit>
#include<QPushButton>

struct AlarmData{
    QTime time;
    QVector<bool>daysOfWeek;
    AlarmData(const QTime& _time, const QVector<bool> _daysOfWeek) : time(_time), daysOfWeek(_daysOfWeek)
    {}
};

class TimeLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    TimeLineEdit(QWidget* parent = nullptr);
    QVector<bool>getSelectedDays()const;
    void setSelectedDays(const QVector<bool>& days);
protected:
    void mousePressEvent(QMouseEvent* event)override;
signals:
    void alarmDataReady(const AlarmData& alarmData);
private:
    QTime selectedTime;
    QVector<bool>selectedDays = QVector<bool>(7, false);
    QTimeEdit* timeEdit;
    QPushButton* okBtn;
    QPushButton* cancelBtn;
public slots:
    void showDialog();

};

#endif // TIMELINEEDIT_H
