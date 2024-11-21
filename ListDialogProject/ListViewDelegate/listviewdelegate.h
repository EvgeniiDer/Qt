#ifndef LISTVIEWDELEGATE_H
#define LISTVIEWDELEGATE_H

#include <QStyledItemDelegate>
#include <QSize>
#include <QPainter>

class ListViewDelegate : public QStyledItemDelegate
{
public:
    ListViewDelegate();
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index)const override;
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index)const override;

private:
};

#endif // LISTVIEWDELEGATE_H
