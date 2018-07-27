/****************************************************************************
** Meta object code from reading C++ file 'QtSpeech_unx.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qtspeech/QtSpeech_unx.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtSpeech_unx.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QtSpeech_v1__WavePlayer[] = {

 // content:
       6,       // revision
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

static const char qt_meta_stringdata_QtSpeech_v1__WavePlayer[] = {
    "QtSpeech_v1::WavePlayer\0"
};

void QtSpeech_v1::WavePlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QtSpeech_v1::WavePlayer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QtSpeech_v1::WavePlayer::staticMetaObject = {
    { &QProcess::staticMetaObject, qt_meta_stringdata_QtSpeech_v1__WavePlayer,
      qt_meta_data_QtSpeech_v1__WavePlayer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtSpeech_v1::WavePlayer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtSpeech_v1::WavePlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtSpeech_v1::WavePlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtSpeech_v1__WavePlayer))
        return static_cast<void*>(const_cast< WavePlayer*>(this));
    return QProcess::qt_metacast(_clname);
}

int QtSpeech_v1::WavePlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QProcess::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_QtSpeech_v1__QtSpeech_proc[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x05,
      61,   27,   27,   27, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,   72,   27,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QtSpeech_v1__QtSpeech_proc[] = {
    "QtSpeech_v1::QtSpeech_proc\0\0"
    "logicError(QtSpeech::LogicError)\0"
    "finished()\0text\0say(QString)\0"
};

void QtSpeech_v1::QtSpeech_proc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QtSpeech_proc *_t = static_cast<QtSpeech_proc *>(_o);
        switch (_id) {
        case 0: _t->logicError((*reinterpret_cast< QtSpeech::LogicError(*)>(_a[1]))); break;
        case 1: _t->finished(); break;
        case 2: _t->say((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QtSpeech_v1::QtSpeech_proc::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QtSpeech_v1::QtSpeech_proc::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QtSpeech_v1__QtSpeech_proc,
      qt_meta_data_QtSpeech_v1__QtSpeech_proc, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QtSpeech_v1::QtSpeech_proc::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QtSpeech_v1::QtSpeech_proc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QtSpeech_v1::QtSpeech_proc::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QtSpeech_v1__QtSpeech_proc))
        return static_cast<void*>(const_cast< QtSpeech_proc*>(this));
    return QObject::qt_metacast(_clname);
}

int QtSpeech_v1::QtSpeech_proc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QtSpeech_v1::QtSpeech_proc::logicError(QtSpeech::LogicError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtSpeech_v1::QtSpeech_proc::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
