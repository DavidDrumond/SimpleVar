/****************************************************************************
** Meta object code from reading C++ file 'parametros_variograma_experimental.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../parametros_variograma_experimental.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parametros_variograma_experimental.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Parametros_Variograma_Experimental_t {
    QByteArrayData data[11];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Parametros_Variograma_Experimental_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Parametros_Variograma_Experimental_t qt_meta_stringdata_Parametros_Variograma_Experimental = {
    {
QT_MOC_LITERAL(0, 0, 34), // "Parametros_Variograma_Experim..."
QT_MOC_LITERAL(1, 35, 25), // "on_ndirecoes_valueChanged"
QT_MOC_LITERAL(2, 61, 0), // ""
QT_MOC_LITERAL(3, 62, 4), // "arg1"
QT_MOC_LITERAL(4, 67, 14), // "botao_apertado"
QT_MOC_LITERAL(5, 82, 17), // "on_clicked_buttom"
QT_MOC_LITERAL(6, 100, 21), // "on_tabela_cellPressed"
QT_MOC_LITERAL(7, 122, 3), // "row"
QT_MOC_LITERAL(8, 126, 6), // "column"
QT_MOC_LITERAL(9, 133, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(10, 155, 23) // "on_pushButton_2_clicked"

    },
    "Parametros_Variograma_Experimental\0"
    "on_ndirecoes_valueChanged\0\0arg1\0"
    "botao_apertado\0on_clicked_buttom\0"
    "on_tabela_cellPressed\0row\0column\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Parametros_Variograma_Experimental[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    2,   49,    2, 0x08 /* Private */,
       9,    0,   54,    2, 0x08 /* Private */,
      10,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Parametros_Variograma_Experimental::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Parametros_Variograma_Experimental *_t = static_cast<Parametros_Variograma_Experimental *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ndirecoes_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->botao_apertado(); break;
        case 2: _t->on_clicked_buttom(); break;
        case 3: _t->on_tabela_cellPressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Parametros_Variograma_Experimental::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Parametros_Variograma_Experimental.data,
      qt_meta_data_Parametros_Variograma_Experimental,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Parametros_Variograma_Experimental::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Parametros_Variograma_Experimental::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Parametros_Variograma_Experimental.stringdata0))
        return static_cast<void*>(const_cast< Parametros_Variograma_Experimental*>(this));
    return QDialog::qt_metacast(_clname);
}

int Parametros_Variograma_Experimental::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
