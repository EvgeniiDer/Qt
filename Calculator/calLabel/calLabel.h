#ifndef CALLABEL_H
#define CALLABEL_H

#include <QLabel>

class CalLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CalLabel(const QString& text, QWidget* parent = nullptr);
};

#endif // CALLABEL_H
