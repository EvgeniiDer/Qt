#include "alarmswindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTime>
#include <QDebug>
#include <QCloseEvent>
#include <QMessageBox>
#include <QRegularExpression>
#include <QCheckBox>
#include <QVector>



AlarmsWindow::AlarmsWindow(QWidget* parent) : QDialog(parent)
{
    this->setWindowTitle("Alarm");
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *timeLayout = new QHBoxLayout();

    timeLineEdit = new TimeLineEdit(this);
    timeLayout->addWidget(timeLineEdit);
    mainLayout->addLayout(timeLayout);

    alarmListWidget = new QListWidget(this);
    mainLayout->addWidget(alarmListWidget);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    removeButton = new QPushButton("Remove", this);
    editButton = new QPushButton("Edit", this);
    exitButton = new QPushButton("Exit", this);


    buttonLayout->addWidget(removeButton);
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(exitButton);

    mainLayout->addLayout(buttonLayout);

    QObject::connect(timeLineEdit, &TimeLineEdit::alarmDataReady, this, &AlarmsWindow::addAlarm);
    QObject::connect(exitButton, &QPushButton::clicked, this, &AlarmsWindow::close);
    QObject::connect(removeButton, &QPushButton::clicked, this, &AlarmsWindow::removeAlarm);
    QObject::connect(editButton, &QPushButton::clicked, this, &AlarmsWindow::editAlarm);

    // Инициализация QMediaPlayer и QAudioOutput
    player = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    player->setAudioOutput(audioOutput);

    // Устанавливаем путь из локального файла
    player->setSource(QUrl::fromLocalFile("/Users/evgenii/Project/Qt/Alarm/Alarm/Sounds/Al.mp3"));
    //audioOutput->setVolume(2.0);
    alarmTimer = new QTimer(this);
    QObject::connect(alarmTimer, &QTimer::timeout, this,[this](){
        this->checkAlarm(QTime::currentTime());
    });
    alarmTimer->start(1000);
}
void AlarmsWindow::editAlarm()//!!!!!
{
    int currentRow = alarmListWidget->currentRow();
    qDebug() << currentRow;
    if(currentRow >= 0)
    {
        //достаем и очищаем элемент
        QListWidgetItem *item = alarmListWidget->takeItem(currentRow);
        alarmDataList.removeAt(currentRow);
        //Удаляем элемент из Списк4а
        delete item;
    }
    timeLineEdit->showDialog();
}
void AlarmsWindow::checkAlarm(QTime currentTime)
{
    for(const auto alarmData: alarmDataList)
    {
        if(alarmData.time.hour() == currentTime.hour() &&
            alarmData.time.minute() == currentTime.minute())
        {
            QDate currentDate = QDate::currentDate();
            int currentDayOfWeek = currentDate.dayOfWeek() - 1;
            if(alarmData.daysOfWeek.isEmpty() || alarmData.daysOfWeek[currentDayOfWeek])
            {
                qDebug() << "Alarm Triggered" << alarmData.time.toString("hh:mm");
                QMessageBox::information(this, "Alarm", "Alarm is Rigining");
                if(player->mediaStatus() != QMediaPlayer::MediaStatus::LoadedMedia)
                {
                    player->setSource(QUrl::fromLocalFile("/Users/evgenii/Project/Qt/Alarm/Alarm/Sounds/Al.mp3"));
                    audioOutput->setVolume(2.0);
                }
                player->play();
            }
        }
    }
}
void AlarmsWindow::removeAlarm()
{
    int currentRow = alarmListWidget->currentRow();
    if(currentRow >= 0)
    {
        alarmListWidget->takeItem(currentRow);
        alarmDataList.removeAt(currentRow);
        qDebug() << "Alarm removed from AlarmList ";
    }

}
void AlarmsWindow::addAlarm(const AlarmData& alarm)
{
    qDebug() << "One";
    alarmDataList.append(alarm);
    qDebug() << "Alarm added to QList<AlarmData>alarmData";
    QString alarmString = alarm.time.toString("HH:mm");
    alarmString += " ";
    for(int i = 0; i < alarm.daysOfWeek.size(); i++)
    {
        if(alarm.daysOfWeek[i] == true)
        {
            switch(i)
            {
            case 0:
                alarmString += " Mon ";
                break;
            case 1:
                alarmString += " Tue ";
                break;
            case 2:
                alarmString += " Wed ";
                break;
            case 3:
                alarmString += " Thu ";
                break;
            case 4:
                alarmString += " Fri ";
                break;
            case 5:
                alarmString += " Sat ";
                break;
            case 6:
                alarmString += " Sun ";
                break;
            }

        }
    }
    bool isExist = false;
    for(int i = 0; i < alarmListWidget->count(); i++)
    {
        if(alarmListWidget->item(i)->text() == alarmString)
        {
            isExist = true;
        }
    }
    if(!isExist)
    {
        alarmDataList.append(alarm);
        qDebug() << "Added!!";
        alarmListWidget->addItem(alarmString);
    }
    else{
        qDebug() << "Alarm Already Exist";
    }

}
