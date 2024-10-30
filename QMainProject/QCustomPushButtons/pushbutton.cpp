#include "pushbutton.h"

PushButton::PushButton(const QString& _buttonText, const int& _buttonW, const int& _buttonH)
{
    buttonText = _buttonText;
    buttonW = _buttonW;
    buttonH = _buttonH;
    setupButton(buttonText, buttonW, buttonH);
}

void PushButton::setupButton(const QString& _buttonText, const int& _buttonW , const int& _buttonH)
{
    this->setText(_buttonText);
    this->setFixedSize(_buttonW, _buttonH);

    connect(this, &QPushButton::clicked, this, &PushButton::openDirectory);
    treeView = new QTreeView(this);
    model = new QStandardItemModel(this);
    treeView->setModel(model);
}
void PushButton::openDirectory()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, "Select Directory");
    if(!dirPath.isEmpty())
        loadDirectory(dirPath);
}
void PushButton::loadDirectory(const QString &_dirPath)
{
    model->clear();
    QDir dir(_dirPath);
    QFileInfoList files = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);

    for(const QFileInfo& fileInfo : files)
    {
        QStandardItem* item = new QStandardItem(fileInfo.fileName());
        model->appendRow(item);
    }
}

