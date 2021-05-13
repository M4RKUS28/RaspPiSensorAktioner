/****************************************************************************
** Meta object code from reading C++ file 'aktionmngr.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../aktionmngr.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aktionmngr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AktionMngr_t {
    const uint offsetsAndSize[22];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AktionMngr_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AktionMngr_t qt_meta_stringdata_AktionMngr = {
    {
QT_MOC_LITERAL(0, 10), // "AktionMngr"
QT_MOC_LITERAL(11, 32), // "on_pushButton_add_aktion_clicked"
QT_MOC_LITERAL(44, 0), // ""
QT_MOC_LITERAL(45, 40), // "on_listWidget_aktionen_itemDo..."
QT_MOC_LITERAL(86, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(103, 4), // "item"
QT_MOC_LITERAL(108, 34), // "on_pushButton_removeAktion_cl..."
QT_MOC_LITERAL(143, 28), // "on_pushButton_moveUp_clicked"
QT_MOC_LITERAL(172, 30), // "on_pushButton_moveDown_clicked"
QT_MOC_LITERAL(203, 22), // "on_label_5_linkHovered"
QT_MOC_LITERAL(226, 4) // "link"

    },
    "AktionMngr\0on_pushButton_add_aktion_clicked\0"
    "\0on_listWidget_aktionen_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0"
    "on_pushButton_removeAktion_clicked\0"
    "on_pushButton_moveUp_clicked\0"
    "on_pushButton_moveDown_clicked\0"
    "on_label_5_linkHovered\0link"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AktionMngr[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    0 /* Private */,
       3,    1,   51,    2, 0x08,    1 /* Private */,
       6,    0,   54,    2, 0x08,    3 /* Private */,
       7,    0,   55,    2, 0x08,    4 /* Private */,
       8,    0,   56,    2, 0x08,    5 /* Private */,
       9,    1,   57,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void AktionMngr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AktionMngr *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_add_aktion_clicked(); break;
        case 1: _t->on_listWidget_aktionen_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_removeAktion_clicked(); break;
        case 3: _t->on_pushButton_moveUp_clicked(); break;
        case 4: _t->on_pushButton_moveDown_clicked(); break;
        case 5: _t->on_label_5_linkHovered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AktionMngr::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AktionMngr.offsetsAndSize,
    qt_meta_data_AktionMngr,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AktionMngr_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *AktionMngr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AktionMngr::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AktionMngr.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AktionMngr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
struct qt_meta_stringdata_AktionExecuterThread_t {
    const uint offsetsAndSize[2];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AktionExecuterThread_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AktionExecuterThread_t qt_meta_stringdata_AktionExecuterThread = {
    {
QT_MOC_LITERAL(0, 20) // "AktionExecuterThread"

    },
    "AktionExecuterThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AktionExecuterThread[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void AktionExecuterThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject AktionExecuterThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_AktionExecuterThread.offsetsAndSize,
    qt_meta_data_AktionExecuterThread,
    qt_static_metacall,
    nullptr,
    nullptr,
    nullptr
} };


const QMetaObject *AktionExecuterThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AktionExecuterThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AktionExecuterThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int AktionExecuterThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
