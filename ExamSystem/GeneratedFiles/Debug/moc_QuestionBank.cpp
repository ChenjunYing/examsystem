/****************************************************************************
** Meta object code from reading C++ file 'QuestionBank.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QuestionBank.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QuestionBank.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QuestionBank_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuestionBank_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuestionBank_t qt_meta_stringdata_QuestionBank = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QuestionBank"
QT_MOC_LITERAL(1, 13, 10), // "showChoice"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "showMultichoice"
QT_MOC_LITERAL(4, 41, 9), // "showJudge"
QT_MOC_LITERAL(5, 51, 12), // "onTabChanged"
QT_MOC_LITERAL(6, 64, 5), // "index"
QT_MOC_LITERAL(7, 70, 19), // "choiceDoubleClicked"
QT_MOC_LITERAL(8, 90, 11) // "dataRefresh"

    },
    "QuestionBank\0showChoice\0\0showMultichoice\0"
    "showJudge\0onTabChanged\0index\0"
    "choiceDoubleClicked\0dataRefresh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuestionBank[] = {

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
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QuestionBank::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuestionBank *_t = static_cast<QuestionBank *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showChoice(); break;
        case 1: _t->showMultichoice(); break;
        case 2: _t->showJudge(); break;
        case 3: _t->onTabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->choiceDoubleClicked(); break;
        case 5: _t->dataRefresh(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QuestionBank::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QuestionBank.data,
      qt_meta_data_QuestionBank,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QuestionBank::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuestionBank::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QuestionBank.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int QuestionBank::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE