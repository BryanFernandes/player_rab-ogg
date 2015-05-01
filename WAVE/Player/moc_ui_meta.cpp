/****************************************************************************
** Meta object code from reading C++ file 'ui_meta.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ui_meta.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ui_meta.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ui_meta[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,   20,   20,   20, 0x05,
      21,   20,   20,   20, 0x05,
      34,   61,   20,   20, 0x05,
      82,   61,   20,   20, 0x05,
     109,  130,   20,   20, 0x05,
     137,  130,   20,   20, 0x05,
     157,   20,   20,   20, 0x05,
     166,  202,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
     214,   20,   20,   20, 0x0a,
     228,   20,   20,   20, 0x0a,
     246,   20,   20,   20, 0x0a,
     268,   20,   20,   20, 0x0a,
     282,   20,   20,   20, 0x0a,
     295,   20,   20,   20, 0x0a,
     302,   20,   20,   20, 0x0a,
     309,   20,   20,   20, 0x0a,
     319,   20,   20,   20, 0x0a,
     331,   20,   20,   20, 0x0a,
     351,  368,   20,   20, 0x0a,
     373,  368,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ui_meta[] = {
    "Ui_meta\0playSound()\0\0pauseSound()\0"
    "nextMark(uint32_t,Format*)\0"
    "timeInSeconds,format\0prevMark(uint32_t,Format*)\0"
    "forwardTime(Format*)\0format\0"
    "rewindTime(Format*)\0remove()\0"
    "update_m_position(uint32_t,Format*)\0"
    "time,format\0playOrPause()\0resetMarkLabels()\0"
    "resetClockAndSlider()\0fastForward()\0"
    "fastRewind()\0next()\0prev()\0levelUp()\0"
    "levelDown()\0changeMarksLabels()\0"
    "updateClock(int)\0time\0change_song_position(int)\0"
};

void Ui_meta::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Ui_meta *_t = static_cast<Ui_meta *>(_o);
        switch (_id) {
        case 0: _t->playSound(); break;
        case 1: _t->pauseSound(); break;
        case 2: _t->nextMark((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< Format*(*)>(_a[2]))); break;
        case 3: _t->prevMark((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< Format*(*)>(_a[2]))); break;
        case 4: _t->forwardTime((*reinterpret_cast< Format*(*)>(_a[1]))); break;
        case 5: _t->rewindTime((*reinterpret_cast< Format*(*)>(_a[1]))); break;
        case 6: _t->remove(); break;
        case 7: _t->update_m_position((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< Format*(*)>(_a[2]))); break;
        case 8: _t->playOrPause(); break;
        case 9: _t->resetMarkLabels(); break;
        case 10: _t->resetClockAndSlider(); break;
        case 11: _t->fastForward(); break;
        case 12: _t->fastRewind(); break;
        case 13: _t->next(); break;
        case 14: _t->prev(); break;
        case 15: _t->levelUp(); break;
        case 16: _t->levelDown(); break;
        case 17: _t->changeMarksLabels(); break;
        case 18: _t->updateClock((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->change_song_position((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Ui_meta::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Ui_meta::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Ui_meta,
      qt_meta_data_Ui_meta, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ui_meta::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ui_meta::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ui_meta::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ui_meta))
        return static_cast<void*>(const_cast< Ui_meta*>(this));
    if (!strcmp(_clname, "Ui_Player"))
        return static_cast< Ui_Player*>(const_cast< Ui_meta*>(this));
    return QObject::qt_metacast(_clname);
}

int Ui_meta::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Ui_meta::playSound()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Ui_meta::pauseSound()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Ui_meta::nextMark(uint32_t _t1, Format * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Ui_meta::prevMark(uint32_t _t1, Format * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Ui_meta::forwardTime(Format * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Ui_meta::rewindTime(Format * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Ui_meta::remove()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Ui_meta::update_m_position(uint32_t _t1, Format * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
