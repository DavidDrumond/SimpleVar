/****************************************************************************
** Meta object code from reading C++ file 'modelagem_variograma.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../modelagem_variograma.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelagem_variograma.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Modelagem_Variograma_t {
    QByteArrayData data[6];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Modelagem_Variograma_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Modelagem_Variograma_t qt_meta_stringdata_Modelagem_Variograma = {
    {
QT_MOC_LITERAL(0, 0, 20), // "Modelagem_Variograma"
QT_MOC_LITERAL(1, 21, 28), // "on_n_estruturas_valueChanged"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 4), // "arg1"
QT_MOC_LITERAL(4, 56, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 78, 23) // "on_pushButton_2_clicked"

    },
    "Modelagem_Variograma\0on_n_estruturas_valueChanged\0"
    "\0arg1\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Modelagem_Variograma[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Modelagem_Variograma::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Modelagem_Variograma *_t = static_cast<Modelagem_Variograma *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_n_estruturas_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Modelagem_Variograma::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Modelagem_Variograma.data,
      qt_meta_data_Modelagem_Variograma,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Modelagem_Variograma::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Modelagem_Variograma::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Modelagem_Variograma.stringdata0))
        return static_cast<void*>(const_cast< Modelagem_Variograma*>(this));
    return QDialog::qt_metacast(_clname);
}

int Modelagem_Variograma::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
