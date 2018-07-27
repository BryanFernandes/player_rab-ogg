/****************************************************************************
** Meta object code from reading C++ file 'accessibility.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "accessibility.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accessibility.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Accessibility[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Accessibility[] = {
    "Accessibility\0\0screenContrast()\0"
};

void Accessibility::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Accessibility *_t = static_cast<Accessibility *>(_o);
        switch (_id) {
        case 0: _t->screenContrast(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Accessibility::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Accessibility::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Accessibility,
      qt_meta_data_Accessibility, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Accessibility::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Accessibility::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Accessibility::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Accessibility))
        return static_cast<void*>(const_cast< Accessibility*>(this));
    if (!strcmp(_clname, "Ui_Player"))
        return static_cast< Ui_Player*>(const_cast< Accessibility*>(this));
    return QObject::qt_metacast(_clname);
}

int Accessibility::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
