#ifndef DELEGATE_H
#define DELEGATE_H

#include <QWidget>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QItemDelegate>


class Delegate:public QItemDelegate
{
public:
    Delegate();
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem & option,
                      const QModelIndex & index) const
    {
        QLineEdit *lineEdit = new QLineEdit(parent);
        // Set validator
        QDoubleValidator *validator = new QDoubleValidator(0, 9999999,4,lineEdit);
        lineEdit->setValidator(validator);
        return lineEdit;
    }
};

#endif // DELEGATE_H
