/****************************************************************************
** Meta object code from reading C++ file 'TestPlayer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Test/TestPlayer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestPlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TestPlayer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      27,   11,   11,   11, 0x08,
      45,   11,   11,   11, 0x08,
      52,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      73,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TestPlayer[] = {
    "TestPlayer\0\0initTestCase()\0cleanupTestCase()\0"
    "init()\0cleanup()\0testSize()\0evilFunction()\0"
};

void TestPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TestPlayer *_t = static_cast<TestPlayer *>(_o);
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->cleanupTestCase(); break;
        case 2: _t->init(); break;
        case 3: _t->cleanup(); break;
        case 4: _t->testSize(); break;
        case 5: _t->evilFunction(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TestPlayer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TestPlayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestPlayer,
      qt_meta_data_TestPlayer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TestPlayer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TestPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TestPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TestPlayer))
        return static_cast<void*>(const_cast< TestPlayer*>(this));
    return QObject::qt_metacast(_clname);
}

int TestPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
