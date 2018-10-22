/****************************************************************************
** Meta object code from reading C++ file 'bridge.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Watcher/bridge.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bridge.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Bridge_t {
    QByteArrayData data[9];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Bridge_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Bridge_t qt_meta_stringdata_Bridge = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Bridge"
QT_MOC_LITERAL(1, 7, 10), // "pushedPage"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "popPage"
QT_MOC_LITERAL(4, 27, 14), // "emitPushedPage"
QT_MOC_LITERAL(5, 42, 11), // "emitPopPage"
QT_MOC_LITERAL(6, 54, 9), // "setObject"
QT_MOC_LITERAL(7, 64, 6), // "object"
QT_MOC_LITERAL(8, 71, 9) // "getObject"

    },
    "Bridge\0pushedPage\0\0popPage\0emitPushedPage\0"
    "emitPopPage\0setObject\0object\0getObject"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Bridge[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x0a /* Public */,
       5,    0,   47,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    7,
    QMetaType::QStringList,

       0        // eod
};

void Bridge::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Bridge *_t = static_cast<Bridge *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pushedPage(); break;
        case 1: _t->popPage(); break;
        case 2: _t->emitPushedPage(); break;
        case 3: _t->emitPopPage(); break;
        case 4: _t->setObject((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 5: { QStringList _r = _t->getObject();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Bridge::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bridge::pushedPage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Bridge::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Bridge::popPage)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Bridge::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Bridge.data,
      qt_meta_data_Bridge,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Bridge::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Bridge::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Bridge.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Bridge::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Bridge::pushedPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Bridge::popPage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
