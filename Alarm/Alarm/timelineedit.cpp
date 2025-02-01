#include "timelineedit.h"
#include<QDialog>

#include<QVBoxLayout>
#include<QHBoxLayout>
#include <QCheckBox>
#include<QDebug>

TimeLineEdit::TimeLineEdit(QWidget* parent) : QLineEdit(parent)
{
    this->setText("Press for Set up Alarm");
}

QVector<bool> TimeLineEdit::getSelectedDays()const
{
    return selectedDays;
}
void TimeLineEdit::setSelectedDays(const QVector<bool>& days)
{
    selectedDays = days;
}
void TimeLineEdit::showDialog()
{

    QDialog dialog(this);
    dialog.setWindowTitle("Select Time and Days");

    QVBoxLayout* mainLayout = new QVBoxLayout(&dialog);
    timeEdit = new QTimeEdit(this);
    timeEdit->setTime(QTime::currentTime());
    mainLayout->addWidget(timeEdit);

    QHBoxLayout* daysOfWeekLayout = new QHBoxLayout();
    QCheckBox *mondayCheckBox = new QCheckBox("Mon", this);
    QCheckBox *tuesdayCheckBox = new QCheckBox("Tue", this);
    QCheckBox *wednesdayCheckBox = new QCheckBox("Wed", this);
    QCheckBox *thursdayCheckBox = new QCheckBox("Thu", this);
    QCheckBox *fridayCheckBox = new QCheckBox("Fri", this);
    QCheckBox *saturdayCheckBox = new QCheckBox("Sat", this);
    QCheckBox *sundayCheckBox = new QCheckBox("Sun", this);

    mondayCheckBox->setChecked(selectedDays[0]);
    tuesdayCheckBox->setChecked(selectedDays[1]);
    wednesdayCheckBox->setChecked(selectedDays[2]);
    thursdayCheckBox->setChecked(selectedDays[3]);
    fridayCheckBox->setChecked(selectedDays[4]);
    saturdayCheckBox->setChecked(selectedDays[5]);
    sundayCheckBox->setChecked(selectedDays[6]);

    daysOfWeekLayout->addWidget(mondayCheckBox);
    daysOfWeekLayout->addWidget(tuesdayCheckBox);
    daysOfWeekLayout->addWidget(wednesdayCheckBox);
    daysOfWeekLayout->addWidget(thursdayCheckBox);
    daysOfWeekLayout->addWidget(fridayCheckBox);
    daysOfWeekLayout->addWidget(saturdayCheckBox);
    daysOfWeekLayout->addWidget(sundayCheckBox);

    mainLayout->addLayout(daysOfWeekLayout);
    okBtn = new QPushButton("Ok", this);
    cancelBtn = new QPushButton("Cancel", this);
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(okBtn);
    btnLayout->addWidget(cancelBtn);
    mainLayout->addLayout(btnLayout);

    QObject::connect(okBtn, &QPushButton::clicked, &dialog, &QDialog::accept);
    QObject::connect(cancelBtn,&QPushButton::clicked, &dialog, &QDialog::reject);

    dialog.setLayout(mainLayout);

    if(dialog.exec() == QDialog::Accepted){

        selectedTime = timeEdit->time();
        this->setText(selectedTime.toString("HH:mm"));
        selectedDays[0] = mondayCheckBox->isChecked();
        selectedDays[1] = tuesdayCheckBox->isChecked();
        selectedDays[2] = wednesdayCheckBox->isChecked();
        selectedDays[3] = thursdayCheckBox->isChecked();
        selectedDays[4] = fridayCheckBox->isChecked();
        selectedDays[5] = saturdayCheckBox->isChecked();
        selectedDays[6] = sundayCheckBox->isChecked();

        AlarmData data(selectedTime, selectedDays);
        emit alarmDataReady(data);
        qDebug() << "Signal timeChanged sent: " << selectedTime.toString();
        qDebug() << "Signal selectedDays sent: ";
        for(int i = 0; i < selectedDays.size(); i++)
        {
            qDebug() << i + 1 << ": " << selectedDays[i];
        }
    }
}
void TimeLineEdit::mousePressEvent(QMouseEvent* event)
{
    //QLineEdit::mousePressEvent(event);

    QDialog dialog(this);
    dialog.setWindowTitle("Select Time and Days");

    QVBoxLayout* mainLayout = new QVBoxLayout(&dialog);
    timeEdit = new QTimeEdit(this);
    timeEdit->setTime(QTime::currentTime());
    mainLayout->addWidget(timeEdit);

    QHBoxLayout* daysOfWeekLayout = new QHBoxLayout();
    QCheckBox *mondayCheckBox = new QCheckBox("Mon", this);
    QCheckBox *tuesdayCheckBox = new QCheckBox("Tue", this);
    QCheckBox *wednesdayCheckBox = new QCheckBox("Wed", this);
    QCheckBox *thursdayCheckBox = new QCheckBox("Thu", this);
    QCheckBox *fridayCheckBox = new QCheckBox("Fri", this);
    QCheckBox *saturdayCheckBox = new QCheckBox("Sat", this);
    QCheckBox *sundayCheckBox = new QCheckBox("Sun", this);

    mondayCheckBox->setChecked(selectedDays[0]);
    tuesdayCheckBox->setChecked(selectedDays[1]);
    wednesdayCheckBox->setChecked(selectedDays[2]);
    thursdayCheckBox->setChecked(selectedDays[3]);
    fridayCheckBox->setChecked(selectedDays[4]);
    saturdayCheckBox->setChecked(selectedDays[5]);
    sundayCheckBox->setChecked(selectedDays[6]);

    daysOfWeekLayout->addWidget(mondayCheckBox);
    daysOfWeekLayout->addWidget(tuesdayCheckBox);
    daysOfWeekLayout->addWidget(wednesdayCheckBox);
    daysOfWeekLayout->addWidget(thursdayCheckBox);
    daysOfWeekLayout->addWidget(fridayCheckBox);
    daysOfWeekLayout->addWidget(saturdayCheckBox);
    daysOfWeekLayout->addWidget(sundayCheckBox);

    mainLayout->addLayout(daysOfWeekLayout);
    okBtn = new QPushButton("Ok", this);
    cancelBtn = new QPushButton("Cancel", this);
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(okBtn);
    btnLayout->addWidget(cancelBtn);
    mainLayout->addLayout(btnLayout);

    QObject::connect(okBtn, &QPushButton::clicked, &dialog, &QDialog::accept);
    QObject::connect(cancelBtn,&QPushButton::clicked, &dialog, &QDialog::reject);

    dialog.setLayout(mainLayout);

    if(dialog.exec() == QDialog::Accepted){

        selectedTime = timeEdit->time();
        this->setText(selectedTime.toString("HH:mm"));
        selectedDays[0] = mondayCheckBox->isChecked();
        selectedDays[1] = tuesdayCheckBox->isChecked();
        selectedDays[2] = wednesdayCheckBox->isChecked();
        selectedDays[3] = thursdayCheckBox->isChecked();
        selectedDays[4] = fridayCheckBox->isChecked();
        selectedDays[5] = saturdayCheckBox->isChecked();
        selectedDays[6] = sundayCheckBox->isChecked();

        AlarmData data(selectedTime, selectedDays);
        emit alarmDataReady(data);
        qDebug() << "Signal timeChanged sent: " << selectedTime.toString();
        qDebug() << "Signal selectedDays sent: ";
        for(int i = 0; i < selectedDays.size(); i++)
        {
            qDebug() << i + 1 << ": " << selectedDays[i];
        }
    }

}
