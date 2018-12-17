/****************************************************************************
** Meta object code from reading C++ file 'AddChoice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AddChoice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddChoice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddChoice_t {
    QByteArrayData data[13];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddChoice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddChoice_t qt_meta_stringdata_AddChoice = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AddChoice"
QT_MOC_LITERAL(1, 10, 8), // "updateOK"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 14), // "sendChoicePage"
QT_MOC_LITERAL(4, 35, 10), // "AddChoice*"
QT_MOC_LITERAL(5, 46, 9), // "checkData"
QT_MOC_LITERAL(6, 56, 15), // "checkUpdateData"
QT_MOC_LITERAL(7, 72, 9), // "resetData"
QT_MOC_LITERAL(8, 82, 13), // "convertAnswer"
QT_MOC_LITERAL(9, 96, 5), // "index"
QT_MOC_LITERAL(10, 102, 11), // "receiveData"
QT_MOC_LITERAL(11, 114, 6), // "Choice"
QT_MOC_LITERAL(12, 121, 1) // "c"

    },
    "AddChoice\0updateOK\0\0sendChoicePage\0"
    "AddChoice*\0checkData\0checkUpdateData\0"
    "resetData\0convertAnswer\0index\0receiveData\0"
    "Choice\0c"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddChoice[] = {

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
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   55,    2, 0x08 /* Private */,
       6,    0,   56,    2, 0x08 /* Private */,
       7,    0,   57,    2, 0x08 /* Private */,
       8,    1,   58,    2, 0x08 /* Private */,
      10,    1,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void AddChoice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddChoice *_t = static_cast<AddChoice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateOK((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendChoicePage((*reinterpret_cast< AddChoice*(*)>(_a[1]))); break;
        case 2: _t->checkData(); break;
        case 3: _t->checkUpdateData(); break;
        case 4: _t->resetData(); break;
        case 5: { QString _r = _t->convertAnswer((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->receiveData((*reinterpret_cast< Choice(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AddChoice* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AddChoice::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddChoice::updateOK)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AddChoice::*)(AddChoice * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AddChoice::sendChoicePage)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AddChoice::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddChoice.data,
      qt_meta_data_AddChoice,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AddChoice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddChoice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddChoice.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddChoice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AddChoice::updateOK(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddChoice::sendChoicePage(AddChoice * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
