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
#include <QtCore/QList>
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
    QByteArrayData data[31];
    char stringdata0[374];
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
QT_MOC_LITERAL(5, 38, 10), // "showChoice"
QT_MOC_LITERAL(6, 49, 15), // "showMultichoice"
QT_MOC_LITERAL(7, 65, 9), // "showJudge"
QT_MOC_LITERAL(8, 75, 12), // "onTabChanged"
QT_MOC_LITERAL(9, 88, 5), // "index"
QT_MOC_LITERAL(10, 94, 13), // "choiceClicked"
QT_MOC_LITERAL(11, 108, 11), // "QModelIndex"
QT_MOC_LITERAL(12, 120, 19), // "choiceDoubleClicked"
QT_MOC_LITERAL(13, 140, 11), // "dataRefresh"
QT_MOC_LITERAL(14, 152, 7), // "keyWord"
QT_MOC_LITERAL(15, 160, 10), // "lowerValue"
QT_MOC_LITERAL(16, 171, 10), // "upperValue"
QT_MOC_LITERAL(17, 182, 6), // "author"
QT_MOC_LITERAL(18, 189, 9), // "receiveOK"
QT_MOC_LITERAL(19, 199, 20), // "setChoiceTableHeader"
QT_MOC_LITERAL(20, 220, 19), // "QStandardItemModel*"
QT_MOC_LITERAL(21, 240, 5), // "model"
QT_MOC_LITERAL(22, 246, 19), // "setJudgeTableHeader"
QT_MOC_LITERAL(23, 266, 22), // "setChoiceModelItemView"
QT_MOC_LITERAL(24, 289, 14), // "QList<Choice>&"
QT_MOC_LITERAL(25, 304, 6), // "choice"
QT_MOC_LITERAL(26, 311, 21), // "setJudgeModelItemView"
QT_MOC_LITERAL(27, 333, 13), // "QList<Judge>&"
QT_MOC_LITERAL(28, 347, 5), // "judge"
QT_MOC_LITERAL(29, 353, 14), // "searchQuestion"
QT_MOC_LITERAL(30, 368, 5) // "reset"

    },
    "QuestionBank\0sendChoiceData\0\0Choice\0"
    "c\0showChoice\0showMultichoice\0showJudge\0"
    "onTabChanged\0index\0choiceClicked\0"
    "QModelIndex\0choiceDoubleClicked\0"
    "dataRefresh\0keyWord\0lowerValue\0"
    "upperValue\0author\0receiveOK\0"
    "setChoiceTableHeader\0QStandardItemModel*\0"
    "model\0setJudgeTableHeader\0"
    "setChoiceModelItemView\0QList<Choice>&\0"
    "choice\0setJudgeModelItemView\0QList<Judge>&\0"
    "judge\0searchQuestion\0reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuestionBank[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    0,  114,    2, 0x08 /* Private */,
       8,    1,  115,    2, 0x08 /* Private */,
      10,    1,  118,    2, 0x08 /* Private */,
      12,    1,  121,    2, 0x08 /* Private */,
      13,    4,  124,    2, 0x08 /* Private */,
      13,    3,  133,    2, 0x28 /* Private | MethodCloned */,
      13,    2,  140,    2, 0x28 /* Private | MethodCloned */,
      13,    1,  145,    2, 0x28 /* Private | MethodCloned */,
      13,    0,  148,    2, 0x28 /* Private | MethodCloned */,
      18,    1,  149,    2, 0x08 /* Private */,
      19,    1,  152,    2, 0x08 /* Private */,
      22,    1,  155,    2, 0x08 /* Private */,
      23,    2,  158,    2, 0x08 /* Private */,
      26,    2,  163,    2, 0x08 /* Private */,
      29,    0,  168,    2, 0x08 /* Private */,
      30,    0,  169,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, 0x80000000 | 11,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::QString,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   14,   15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   14,   15,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 24,   21,   25,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 27,   21,   28,
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
        case 0: _t->sendChoiceData((*reinterpret_cast< Choice(*)>(_a[1]))); break;
        case 1: _t->showChoice(); break;
        case 2: _t->showMultichoice(); break;
        case 3: _t->showJudge(); break;
        case 4: _t->onTabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->choiceClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->choiceDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: _t->dataRefresh((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 8: _t->dataRefresh((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->dataRefresh((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->dataRefresh((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->dataRefresh(); break;
        case 12: _t->receiveOK((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setChoiceTableHeader((*reinterpret_cast< QStandardItemModel*(*)>(_a[1]))); break;
        case 14: _t->setJudgeTableHeader((*reinterpret_cast< QStandardItemModel*(*)>(_a[1]))); break;
        case 15: _t->setChoiceModelItemView((*reinterpret_cast< QStandardItemModel*(*)>(_a[1])),(*reinterpret_cast< QList<Choice>(*)>(_a[2]))); break;
        case 16: _t->setJudgeModelItemView((*reinterpret_cast< QStandardItemModel*(*)>(_a[1])),(*reinterpret_cast< QList<Judge>(*)>(_a[2]))); break;
        case 17: _t->searchQuestion(); break;
        case 18: _t->reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void QuestionBank::sendChoiceData(Choice _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
