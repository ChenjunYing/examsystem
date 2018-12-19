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
    QByteArrayData data[18];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QuestionBank_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QuestionBank_t qt_meta_stringdata_QuestionBank = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QuestionBank"
QT_MOC_LITERAL(1, 13, 14), // "sendChoiceData"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 6), // "Choice"
QT_MOC_LITERAL(4, 36, 1), // "c"
QT_MOC_LITERAL(5, 38, 19), // "sendMultiChoiceData"
QT_MOC_LITERAL(6, 58, 13), // "sendJudgeData"
QT_MOC_LITERAL(7, 72, 5), // "Judge"
QT_MOC_LITERAL(8, 78, 10), // "showChoice"
QT_MOC_LITERAL(9, 89, 15), // "showMultichoice"
QT_MOC_LITERAL(10, 105, 9), // "showJudge"
QT_MOC_LITERAL(11, 115, 12), // "onTabChanged"
QT_MOC_LITERAL(12, 128, 5), // "index"
QT_MOC_LITERAL(13, 134, 19), // "choiceDoubleClicked"
QT_MOC_LITERAL(14, 154, 18), // "multiDoubleClicked"
QT_MOC_LITERAL(15, 173, 18), // "judgeDoubleClicked"
QT_MOC_LITERAL(16, 192, 11), // "dataRefresh"
QT_MOC_LITERAL(17, 204, 9) // "receiveOK"

    },
    "QuestionBank\0sendChoiceData\0\0Choice\0"
    "c\0sendMultiChoiceData\0sendJudgeData\0"
    "Judge\0showChoice\0showMultichoice\0"
    "showJudge\0onTabChanged\0index\0"
    "choiceDoubleClicked\0multiDoubleClicked\0"
    "judgeDoubleClicked\0dataRefresh\0receiveOK"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuestionBank[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   83,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    1,   86,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    0,   90,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,
      16,    0,   92,    2, 0x08 /* Private */,
      17,    1,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void QuestionBank::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuestionBank *_t = static_cast<QuestionBank *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendChoiceData((*reinterpret_cast< Choice(*)>(_a[1]))); break;
        case 1: _t->sendMultiChoiceData((*reinterpret_cast< Choice(*)>(_a[1]))); break;
        case 2: _t->sendJudgeData((*reinterpret_cast< Judge(*)>(_a[1]))); break;
        case 3: _t->showChoice(); break;
        case 4: _t->showMultichoice(); break;
        case 5: _t->showJudge(); break;
        case 6: _t->onTabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->choiceDoubleClicked(); break;
        case 8: _t->multiDoubleClicked(); break;
        case 9: _t->judgeDoubleClicked(); break;
        case 10: _t->dataRefresh(); break;
        case 11: _t->receiveOK((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QuestionBank::*)(Choice );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QuestionBank::sendChoiceData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QuestionBank::*)(Choice );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QuestionBank::sendMultiChoiceData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QuestionBank::*)(Judge );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QuestionBank::sendJudgeData)) {
                *result = 2;
                return;
            }
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QuestionBank::sendChoiceData(Choice _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QuestionBank::sendMultiChoiceData(Choice _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QuestionBank::sendJudgeData(Judge _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
