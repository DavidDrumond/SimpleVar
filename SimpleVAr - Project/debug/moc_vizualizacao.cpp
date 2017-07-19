/****************************************************************************
** Meta object code from reading C++ file 'vizualizacao.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../vizualizacao.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vizualizacao.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_vizualizacao_t {
    QByteArrayData data[15];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_vizualizacao_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_vizualizacao_t qt_meta_stringdata_vizualizacao = {
    {
QT_MOC_LITERAL(0, 0, 12), // "vizualizacao"
QT_MOC_LITERAL(1, 13, 31), // "on_horizontalSlider_sliderMoved"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 8), // "position"
QT_MOC_LITERAL(4, 55, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(5, 79, 29), // "on_verticalSlider_sliderMoved"
QT_MOC_LITERAL(6, 109, 24), // "on_nclasses_valueChanged"
QT_MOC_LITERAL(7, 134, 4), // "arg1"
QT_MOC_LITERAL(8, 139, 21), // "on_tabela_cellPressed"
QT_MOC_LITERAL(9, 161, 3), // "row"
QT_MOC_LITERAL(10, 165, 6), // "column"
QT_MOC_LITERAL(11, 172, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(12, 194, 23), // "on_Azimute_valueChanged"
QT_MOC_LITERAL(13, 218, 24), // "on_Mergulho_valueChanged"
QT_MOC_LITERAL(14, 243, 23) // "on_pushButton_2_clicked"

    },
    "vizualizacao\0on_horizontalSlider_sliderMoved\0"
    "\0position\0on_pushButton_3_clicked\0"
    "on_verticalSlider_sliderMoved\0"
    "on_nclasses_valueChanged\0arg1\0"
    "on_tabela_cellPressed\0row\0column\0"
    "on_pushButton_clicked\0on_Azimute_valueChanged\0"
    "on_Mergulho_valueChanged\0"
    "on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_vizualizacao[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    0,   62,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       6,    1,   66,    2, 0x08 /* Private */,
       8,    2,   69,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x08 /* Private */,
      13,    1,   78,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void vizualizacao::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        vizualizacao *_t = static_cast<vizualizacao *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_3_clicked(); break;
        case 2: _t->on_verticalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_nclasses_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_tabela_cellPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_Azimute_valueChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_Mergulho_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject vizualizacao::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_vizualizacao.data,
      qt_meta_data_vizualizacao,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *vizualizacao::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *vizualizacao::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_vizualizacao.stringdata0))
        return static_cast<void*>(const_cast< vizualizacao*>(this));
    return QDialog::qt_metacast(_clname);
}

int vizualizacao::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
