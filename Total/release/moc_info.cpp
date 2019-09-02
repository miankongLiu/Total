/****************************************************************************
** Meta object code from reading C++ file 'info.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../info.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'info.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_info_t {
    QByteArrayData data[14];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_info_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_info_t qt_meta_stringdata_info = {
    {
QT_MOC_LITERAL(0, 0, 4), // "info"
QT_MOC_LITERAL(1, 5, 8), // "sendData"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 31, 1), // "d"
QT_MOC_LITERAL(5, 33, 16), // "QVector<QString>"
QT_MOC_LITERAL(6, 50, 1), // "m"
QT_MOC_LITERAL(7, 52, 7), // "sendStr"
QT_MOC_LITERAL(8, 60, 1), // "s"
QT_MOC_LITERAL(9, 62, 16), // "on_pb_ex_clicked"
QT_MOC_LITERAL(10, 79, 16), // "on_pb_im_clicked"
QT_MOC_LITERAL(11, 96, 17), // "on_pb_yes_clicked"
QT_MOC_LITERAL(12, 114, 20), // "on_pb_cancel_clicked"
QT_MOC_LITERAL(13, 135, 11) // "displayInfo"

    },
    "info\0sendData\0\0QVector<double>\0d\0"
    "QVector<QString>\0m\0sendStr\0s\0"
    "on_pb_ex_clicked\0on_pb_im_clicked\0"
    "on_pb_yes_clicked\0on_pb_cancel_clicked\0"
    "displayInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_info[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,
       7,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   57,    2, 0x08 /* Private */,
      10,    0,   58,    2, 0x08 /* Private */,
      11,    0,   59,    2, 0x08 /* Private */,
      12,    0,   60,    2, 0x08 /* Private */,
      13,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 5,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void info::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        info *_t = static_cast<info *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<QString>(*)>(_a[2]))); break;
        case 1: _t->sendStr((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        case 2: _t->on_pb_ex_clicked(); break;
        case 3: _t->on_pb_im_clicked(); break;
        case 4: _t->on_pb_yes_clicked(); break;
        case 5: _t->on_pb_cancel_clicked(); break;
        case 6: _t->displayInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (info::*_t)(QVector<double> , QVector<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&info::sendData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (info::*_t)(QVector<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&info::sendStr)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject info::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_info.data,
      qt_meta_data_info,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *info::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *info::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_info.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int info::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void info::sendData(QVector<double> _t1, QVector<QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void info::sendStr(QVector<QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
