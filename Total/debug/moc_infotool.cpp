/****************************************************************************
** Meta object code from reading C++ file 'infotool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../infotool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infotool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_infoTool_t {
    QByteArrayData data[10];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_infoTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_infoTool_t qt_meta_stringdata_infoTool = {
    {
QT_MOC_LITERAL(0, 0, 8), // "infoTool"
QT_MOC_LITERAL(1, 9, 9), // "sendData_"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 36, 1), // "d"
QT_MOC_LITERAL(5, 38, 16), // "on_pb_ex_clicked"
QT_MOC_LITERAL(6, 55, 16), // "on_pb_im_clicked"
QT_MOC_LITERAL(7, 72, 17), // "on_pb_yes_clicked"
QT_MOC_LITERAL(8, 90, 20), // "on_pb_cancel_clicked"
QT_MOC_LITERAL(9, 111, 15) // "displayInfoTool"

    },
    "infoTool\0sendData_\0\0QVector<double>\0"
    "d\0on_pb_ex_clicked\0on_pb_im_clicked\0"
    "on_pb_yes_clicked\0on_pb_cancel_clicked\0"
    "displayInfoTool"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_infoTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    0,   50,    2, 0x08 /* Private */,
       9,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void infoTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        infoTool *_t = static_cast<infoTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData_((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 1: _t->on_pb_ex_clicked(); break;
        case 2: _t->on_pb_im_clicked(); break;
        case 3: _t->on_pb_yes_clicked(); break;
        case 4: _t->on_pb_cancel_clicked(); break;
        case 5: _t->displayInfoTool(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (infoTool::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&infoTool::sendData_)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject infoTool::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_infoTool.data,
      qt_meta_data_infoTool,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *infoTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *infoTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_infoTool.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int infoTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void infoTool::sendData_(QVector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
