/****************************************************************************
** Meta object code from reading C++ file 'Interface.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Interface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Interface[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      31,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   10,   10,   10, 0x0a,
      78,   73,   10,   10, 0x0a,
     104,   10,   10,   10, 0x08,
     128,   10,   10,   10, 0x08,
     145,   10,   10,   10, 0x08,
     165,   10,   10,   10, 0x08,
     178,   10,   10,   10, 0x08,
     195,   10,   10,   10, 0x08,
     221,   10,   10,   10, 0x08,
     239,   10,   10,   10, 0x08,
     259,   10,   10,   10, 0x08,
     278,   10,   10,   10, 0x08,
     294,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Interface[] = {
    "Interface\0\0connIsupdated(bool)\0"
    "onConnectedMode()\0updateFileName(QString)\0"
    "data\0sendCommands(const char*)\0"
    "handleOnConnectedMode()\0startConnTimer()\0"
    "checkGCSConnState()\0startTimer()\0"
    "sendTensionReq()\0readDigitalCompassSData()\0"
    "readHeliumSData()\0readBallonetSData()\0"
    "readWeatherSData()\0readADAMSData()\0"
    "readEBoxData()\0"
};

void Interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Interface *_t = static_cast<Interface *>(_o);
        switch (_id) {
        case 0: _t->connIsupdated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onConnectedMode(); break;
        case 2: _t->updateFileName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendCommands((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 4: _t->handleOnConnectedMode(); break;
        case 5: _t->startConnTimer(); break;
        case 6: _t->checkGCSConnState(); break;
        case 7: _t->startTimer(); break;
        case 8: _t->sendTensionReq(); break;
        case 9: _t->readDigitalCompassSData(); break;
        case 10: _t->readHeliumSData(); break;
        case 11: _t->readBallonetSData(); break;
        case 12: _t->readWeatherSData(); break;
        case 13: _t->readADAMSData(); break;
        case 14: _t->readEBoxData(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Interface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Interface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Interface,
      qt_meta_data_Interface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Interface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Interface))
        return static_cast<void*>(const_cast< Interface*>(this));
    return QObject::qt_metacast(_clname);
}

int Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Interface::connIsupdated(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Interface::onConnectedMode()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
