#include "listviewdelegate.h"

ListViewDelegate::ListViewDelegate() {}

QSize ListViewDelegate::sizeHint(const QStyleOptionViewItem &option,
                                 const QModelIndex &index)const

{
    return QSize(200, 50);
}
void ListViewDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::black);


    bool isEditing = option.state & QStyle::State_HasFocus;

    if (isEditing) {
        painter->fillRect(option.rect, Qt::gray);
    } else {
        painter->fillRect(option.rect, option.state & QStyle::State_Selected ? Qt::lightGray : Qt::white);
    }


    painter->drawText(option.rect, Qt::AlignCenter, index.data().toString());
    painter->restore();
}
