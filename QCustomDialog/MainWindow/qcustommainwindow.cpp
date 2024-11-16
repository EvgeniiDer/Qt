#include "qcustommainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{

    this->resize(900, 400);
    this->setFixedSize(900, 370);
    centralWidget = new QWidget();
    this->setCentralWidget(centralWidget);



    bttnOk = new QPushButton("Применить", centralWidget);
    bttnCancel = new QPushButton("Cancel", centralWidget);
    bttnAdd = new QPushButton("Add", centralWidget);
    bttnRem = new QPushButton("Remove", centralWidget);
    bttnAddNewLine = new QPushButton("Add New Line", centralWidget);
    bttnDeleteLine = new QPushButton("Delete Line", centralWidget);
    txtEditLeft = new QTextEdit(centralWidget);
    txtEditRight = new QTextEdit(centralWidget);


    txtEditLeft->setGeometry(10, 10, 380, 300);
    txtEditRight->setGeometry(510, 10, 380, 300);

    bttnAdd->setGeometry(400, 100, 100, 30);
    bttnRem->setGeometry(400, 140, 100, 30);

    bttnOk->setGeometry(650, 320, 100, 40);
    bttnCancel->setGeometry(760, 320, 100, 40);

    bttnAddNewLine->setGeometry(20, 320, 100, 40);
    bttnDeleteLine->setGeometry(130, 320, 100, 40);

    connect(bttnCancel, &QPushButton::clicked, this, &MainWindow::onCloseButtonSlot);
    connect(bttnOk, &QPushButton::clicked, this, &MainWindow::onOkButtonSlot);
    connect(bttnAddNewLine, &QPushButton::clicked, this, &MainWindow::onAddNewLineSlot);
    connect(bttnAdd, &QPushButton::clicked, this, &MainWindow::onAddFromLeftToRightSlot);
    connect(bttnRem, &QPushButton::clicked, this, &MainWindow::onRemoveFromRightToLeftSlot);
    connect(bttnDeleteLine, &QPushButton::clicked, this, &MainWindow::onDeleteFromLeftSlot);
}
void MainWindow::onCloseButtonSlot()
{
    qDebug() << "Closing application..";
    close();
}
void MainWindow::onOkButtonSlot()
{
    qDebug() << "Done....";
    close();
}
void MainWindow::onAddNewLineSlot()
{
    bool ok = true;
    QString text = QInputDialog::getText(this, tr("Add information"), tr("Enter text"), QLineEdit::Normal, "", &ok);
    if(ok && !text.isEmpty())
    {
        txtEditLeft->append(text);
    }
}
void MainWindow::onDeleteFromLeftSlot()
{
    removeLine(txtEditLeft);
    removeEmptyLines(txtEditLeft);

}
void MainWindow::removeLine(QTextEdit *textEdit)
{
    QTextCursor cursor = textEdit->textCursor();
    cursor.movePosition(QTextCursor::StartOfBlock);
    int statr = cursor.positionInBlock();
    cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
    cursor.removeSelectedText();
    if(cursor.position() < textEdit->document()->blockCount() - 1)
        {
            cursor.deleteChar();
        }
    textEdit->setTextCursor(cursor);

}
void MainWindow::onRemoveFromRightToLeftSlot()
{
    QTextCursor cursor = txtEditRight->textCursor();
    int lineNumber = cursor.blockNumber();
    QString lineText = txtEditRight->document()->findBlockByNumber(lineNumber).text();
    txtEditLeft->append(lineText);
    cursor.movePosition(QTextCursor::StartOfBlock);
    cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
    cursor.removeSelectedText(); // Удаляем текст из правого редактора
    removeEmptyLines(txtEditRight);
}

void MainWindow::onAddFromLeftToRightSlot()
{
    QTextCursor cursor = txtEditLeft->textCursor();
    int lineNumber = cursor.blockNumber();
    QString lineText = txtEditLeft->document()->findBlockByNumber(lineNumber).text();
    txtEditRight->append(lineText);
    cursor.movePosition(QTextCursor::StartOfBlock);
    cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
    cursor.removeSelectedText(); // Удаляем текст из левого редактора
    removeEmptyLines(txtEditLeft);
}

void MainWindow::removeEmptyLines(QTextEdit *textEdit)
{
    QTextDocument *doc = textEdit->document();
    QTextCursor cursor(textEdit->textCursor());

    for (int i = doc->blockCount() - 1; i >= 0; --i) {
        QTextBlock block = doc->findBlockByNumber(i);
        if (block.text().trimmed().isEmpty())
            {
                cursor.setPosition(block.position());
                cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
                cursor.removeSelectedText();
                if (i > 0)
                    {
                        cursor.setPosition(block.position() - 1);
                        cursor.deleteChar();
                    }
            }
    }
}


