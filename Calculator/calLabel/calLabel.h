#ifndef CALLABEL_H
#define CALLABEL_H

#include <QLabel>

class CalLabel : public QLabel
{
public:
    explicit CalLabel(const QString& text, QWidget* parent = nullptr);
};

#endif // CALLABEL_H
