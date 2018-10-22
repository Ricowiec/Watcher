/****************************************************************************
** Meta object code from reading C++ file 'api.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Watcher/api.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'api.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_API_t {
    QByteArrayData data[22];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_API_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_API_t qt_meta_stringdata_API = {
    {
QT_MOC_LITERAL(0, 0, 3), // "API"
QT_MOC_LITERAL(1, 4, 9), // "readyRead"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 16), // "downloadFinished"
QT_MOC_LITERAL(4, 32, 14), // "QNetworkReply*"
QT_MOC_LITERAL(5, 47, 5), // "reply"
QT_MOC_LITERAL(6, 53, 13), // "requestToCurl"
QT_MOC_LITERAL(7, 67, 7), // "request"
QT_MOC_LITERAL(8, 75, 7), // "getData"
QT_MOC_LITERAL(9, 83, 3), // "txt"
QT_MOC_LITERAL(10, 87, 17), // "getReturnedObject"
QT_MOC_LITERAL(11, 105, 10), // "objectName"
QT_MOC_LITERAL(12, 116, 10), // "jsonParser"
QT_MOC_LITERAL(13, 127, 8), // "fileName"
QT_MOC_LITERAL(14, 136, 14), // "getObjectsList"
QT_MOC_LITERAL(15, 151, 14), // "setCurrentPage"
QT_MOC_LITERAL(16, 166, 6), // "number"
QT_MOC_LITERAL(17, 173, 14), // "getCurrentPage"
QT_MOC_LITERAL(18, 188, 16), // "setElementsLimit"
QT_MOC_LITERAL(19, 205, 5), // "limit"
QT_MOC_LITERAL(20, 211, 16), // "getElementsLimit"
QT_MOC_LITERAL(21, 228, 20) // "getCurrentSearchText"

    },
    "API\0readyRead\0\0downloadFinished\0"
    "QNetworkReply*\0reply\0requestToCurl\0"
    "request\0getData\0txt\0getReturnedObject\0"
    "objectName\0jsonParser\0fileName\0"
    "getObjectsList\0setCurrentPage\0number\0"
    "getCurrentPage\0setElementsLimit\0limit\0"
    "getElementsLimit\0getCurrentSearchText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_API[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   80,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       6,    1,   83,    2, 0x02 /* Public */,
       7,    1,   86,    2, 0x02 /* Public */,
       8,    1,   89,    2, 0x02 /* Public */,
      10,    1,   92,    2, 0x02 /* Public */,
      12,    1,   95,    2, 0x02 /* Public */,
      14,    1,   98,    2, 0x02 /* Public */,
      15,    1,  101,    2, 0x02 /* Public */,
      17,    0,  104,    2, 0x02 /* Public */,
      18,    1,  105,    2, 0x02 /* Public */,
      20,    0,  108,    2, 0x02 /* Public */,
      21,    0,  109,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::QString, QMetaType::QString,    9,
    QMetaType::QStringList, QMetaType::QString,   11,
    QMetaType::Bool, QMetaType::QString,   13,
    QMetaType::QStringList, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::UInt,   16,
    QMetaType::UInt,
    QMetaType::Void, QMetaType::UInt,   19,
    QMetaType::UInt,
    QMetaType::QString,

       0        // eod
};

void API::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        API *_t = static_cast<API *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readyRead(); break;
        case 1: _t->downloadFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->requestToCurl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->request((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: { QString _r = _t->getData((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QStringList _r = _t->getReturnedObject((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->jsonParser((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { QStringList _r = _t->getObjectsList((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->setCurrentPage((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 9: { uint _r = _t->getCurrentPage();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->setElementsLimit((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 11: { uint _r = _t->getElementsLimit();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 12: { QString _r = _t->getCurrentSearchText();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (API::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&API::readyRead)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject API::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_API.data,
      qt_meta_data_API,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *API::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *API::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_API.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int API::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void API::readyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
