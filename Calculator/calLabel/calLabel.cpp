#include "calLabel.h"

CalLabel::CalLabel(const QString& text, QWidget* parent) :QLabel(text, parent)
{
    this->setAlignment(Qt::AlignRight);
    QFont fnt("Arial", 20, QFont::Normal);
    this->setFont(fnt);
    QPalette plt = this->palette();
    plt.setColor(QPalette::WindowText, Qt::darkGray);
    this->setPalette(plt);

}
