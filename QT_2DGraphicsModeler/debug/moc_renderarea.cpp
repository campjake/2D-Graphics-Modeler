/****************************************************************************
** Meta object code from reading C++ file 'renderarea.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../renderarea.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renderarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_RenderArea_t {
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[9];
    char stringdata5[6];
    char stringdata6[15];
    char stringdata7[12];
    char stringdata8[15];
    char stringdata9[12];
    char stringdata10[8];
    char stringdata11[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_RenderArea_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_RenderArea_t qt_meta_stringdata_RenderArea = {
    {
        QT_MOC_LITERAL(0, 10),  // "RenderArea"
        QT_MOC_LITERAL(11, 6),  // "setPen"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 3),  // "pen"
        QT_MOC_LITERAL(23, 8),  // "setBrush"
        QT_MOC_LITERAL(32, 5),  // "brush"
        QT_MOC_LITERAL(38, 14),  // "setAntialiased"
        QT_MOC_LITERAL(53, 11),  // "antialiased"
        QT_MOC_LITERAL(65, 14),  // "setTransformed"
        QT_MOC_LITERAL(80, 11),  // "transformed"
        QT_MOC_LITERAL(92, 7),  // "setMove"
        QT_MOC_LITERAL(100, 6)   // "newPos"
    },
    "RenderArea",
    "setPen",
    "",
    "pen",
    "setBrush",
    "brush",
    "setAntialiased",
    "antialiased",
    "setTransformed",
    "transformed",
    "setMove",
    "newPos"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_RenderArea[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       4,    1,   47,    2, 0x0a,    3 /* Public */,
       6,    1,   50,    2, 0x0a,    5 /* Public */,
       8,    1,   53,    2, 0x0a,    7 /* Public */,
      10,    1,   56,    2, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPen,    3,
    QMetaType::Void, QMetaType::QBrush,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::QPoint,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject RenderArea::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_RenderArea.offsetsAndSizes,
    qt_meta_data_RenderArea,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_RenderArea_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RenderArea, std::true_type>,
        // method 'setPen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPen &, std::false_type>,
        // method 'setBrush'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QBrush &, std::false_type>,
        // method 'setAntialiased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setTransformed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>
    >,
    nullptr
} };

void RenderArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderArea *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setPen((*reinterpret_cast< std::add_pointer_t<QPen>>(_a[1]))); break;
        case 1: _t->setBrush((*reinterpret_cast< std::add_pointer_t<QBrush>>(_a[1]))); break;
        case 2: _t->setAntialiased((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->setTransformed((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->setMove((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *RenderArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RenderArea.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RenderArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
