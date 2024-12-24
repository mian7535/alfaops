/****************************************************************************
** Meta object code from reading C++ file 'GCSMainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../GUI/GCSMainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GCSMainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GCSMainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   22,   14,   14, 0x0a,
      52,   14,   14,   14, 0x08,
      65,   14,   14,   14, 0x08,
      88,   14,   14,   14, 0x08,
     110,   14,   14,   14, 0x08,
     133,   14,   14,   14, 0x08,
     155,   14,   14,   14, 0x08,
     180,   14,   14,   14, 0x08,
     204,   14,   14,   14, 0x08,
     231,   14,   14,   14, 0x08,
     257,   14,   14,   14, 0x08,
     270,   14,   14,   14, 0x08,
     285,   14,   14,   14, 0x08,
     295,   14,   14,   14, 0x08,
     302,   14,   14,   14, 0x08,
     316,   14,   14,   14, 0x08,
     336,   14,   14,   14, 0x08,
     359,   14,   14,   14, 0x08,
     375,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GCSMainWindow[] = {
    "GCSMainWindow\0\0done()\0status\0"
    "updateConnStatus(bool)\0updateTime()\0"
    "handleFan1OffControl()\0handleFan1OnControl()\0"
    "handleFan2OffControl()\0handleFan2OnControl()\0"
    "handleStrobeOffControl()\0"
    "handleStrobeOnControl()\0"
    "handlePositionOffControl()\0"
    "handlePositionOnControl()\0browseFile()\0"
    "startPlaying()\0FWDData()\0stop()\0"
    "emptyFields()\0updateDisplayType()\0"
    "clearDisplayTypeText()\0finishReading()\0"
    "updateGUIFromLog()\0"
};

void GCSMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GCSMainWindow *_t = static_cast<GCSMainWindow *>(_o);
        switch (_id) {
        case 0: _t->done(); break;
        case 1: _t->updateConnStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->updateTime(); break;
        case 3: _t->handleFan1OffControl(); break;
        case 4: _t->handleFan1OnControl(); break;
        case 5: _t->handleFan2OffControl(); break;
        case 6: _t->handleFan2OnControl(); break;
        case 7: _t->handleStrobeOffControl(); break;
        case 8: _t->handleStrobeOnControl(); break;
        case 9: _t->handlePositionOffControl(); break;
        case 10: _t->handlePositionOnControl(); break;
        case 11: _t->browseFile(); break;
        case 12: _t->startPlaying(); break;
        case 13: _t->FWDData(); break;
        case 14: _t->stop(); break;
        case 15: _t->emptyFields(); break;
        case 16: _t->updateDisplayType(); break;
        case 17: _t->clearDisplayTypeText(); break;
        case 18: _t->finishReading(); break;
        case 19: _t->updateGUIFromLog(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GCSMainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GCSMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GCSMainWindow,
      qt_meta_data_GCSMainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GCSMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GCSMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GCSMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GCSMainWindow))
        return static_cast<void*>(const_cast< GCSMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GCSMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void GCSMainWindow::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
