/****************************************************************************
** Meta object code from reading C++ file 'webcamget.h'
**
** Created: Sun Mar 24 22:40:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../webcamget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webcamget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_webcamGet[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x08,
      47,   10,   10,   10, 0x08,
      90,   84,   10,   10, 0x08,
     118,   10,   10,   10, 0x08,
     142,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_webcamGet[] = {
    "webcamGet\0\0img\0averageColorCalculation(QImage)\0"
    "on_comboBox_currentIndexChanged(int)\0"
    "state\0on_smooth_stateChanged(int)\0"
    "on_openButton_clicked()\0on_saveButton_clicked()\0"
};

void webcamGet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        webcamGet *_t = static_cast<webcamGet *>(_o);
        switch (_id) {
        case 0: _t->averageColorCalculation((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_smooth_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_openButton_clicked(); break;
        case 4: _t->on_saveButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData webcamGet::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject webcamGet::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_webcamGet,
      qt_meta_data_webcamGet, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &webcamGet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *webcamGet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *webcamGet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_webcamGet))
        return static_cast<void*>(const_cast< webcamGet*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int webcamGet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
