#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
{
    this->setWindowTitle("Add Entry");
    centralWidget = new QWidget(this);
    centralWidget->setFixedSize(600, 300);
    this->setCentralWidget(centralWidget);

    strList = new QStringList();
    *strList << "Element1" << "Elemnet2" << "Element3" << "Element3";
    strListModel = new QStringListModel(*strList);


    lstView = new QListView(centralWidget);
    lstView->setModel(strListModel);
    lstView->setGeometry(10, 10, 580, 240);
    viewDlg = new ListViewDelegate();
    lstView->setItemDelegate(viewDlg);

    btnOk = new QPushButton("Ok",centralWidget);
    btnCancel = new QPushButton("Cancel",centralWidget);
    btnAdd = new QPushButton("Add", centralWidget);
    btnRem = new QPushButton("Remove",centralWidget);

    btnCancel->setGeometry(490, 260, 100, 30);
    btnOk->setGeometry(380, 260, 100, 30);

    btnAdd->setGeometry(10, 260, 100, 30);
    btnRem->setGeometry(120, 260, 100, 30);


    connect(btnCancel, &QPushButton::clicked, this, &MainWindow::onCancelBtnSlot);
    connect(btnOk, &QPushButton::clicked, this, &MainWindow::onOkBtnSlot);
    connect(btnAdd, &QPushButton::clicked, this, &MainWindow::onAddBtnSlot);
    connect(btnRem, &QPushButton::clicked, this, &MainWindow::onRemBtnSlot);
}
void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        onAddBtnSlot();
    }
    else if(event->key() == Qt::Key_Delete || event->key() == Qt::Key_Backspace)
    {
        onRemBtnSlot();
    }
}
void MainWindow::onAddBtnSlot()
{
    bool ok;
    QString newItem = QInputDialog::getText(this, "Add Element", "Enter New Element:", QLineEdit::Normal, "", &ok);

    if (ok && !newItem.isEmpty()) {
        strList->append(newItem);
        strListModel->setStringList(*strList);
    } else if (ok) {
        QMessageBox::warning(this, "Error", "Enter new Element!");
    }
}
void MainWindow::onRemBtnSlot()
{
    QModelIndex selectedIndex = lstView->currentIndex();
    if(selectedIndex.isValid())
    {
        strList->removeAt(selectedIndex.row());
        strListModel->setStringList(*strList);
    }else
    {
        QMessageBox::information(this,"Erro", "Element not Selected");
    }
}
void MainWindow::onCancelBtnSlot()
{
    close();
}
void MainWindow::onOkBtnSlot()
{
    QModelIndex selectedIndex = lstView->currentIndex();
    if(selectedIndex.isValid())
    {
        int itemNumber = selectedIndex.row() + 1;
        QMessageBox::information(this, "Selected Item", QString("Selected Element number: %1").arg(itemNumber));
    }
    else
    {
        QMessageBox::information(this, "Error", "Element not selected");
    }
}

