/****************************************************************************
** Meta object code from reading C++ file 'scene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "scene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GScene_t {
    QByteArrayData data[25];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GScene_t qt_meta_stringdata_GScene = {
    {
QT_MOC_LITERAL(0, 0, 6), // "GScene"
QT_MOC_LITERAL(1, 7, 15), // "setModeSelected"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "setModeInsert"
QT_MOC_LITERAL(4, 38, 10), // "setOpacity"
QT_MOC_LITERAL(5, 49, 2), // "op"
QT_MOC_LITERAL(6, 52, 12), // "setLineWidth"
QT_MOC_LITERAL(7, 65, 6), // "lwidth"
QT_MOC_LITERAL(8, 72, 9), // "setTypeEl"
QT_MOC_LITERAL(9, 82, 10), // "setTypeZig"
QT_MOC_LITERAL(10, 93, 10), // "setTypeSek"
QT_MOC_LITERAL(11, 104, 10), // "deleteItem"
QT_MOC_LITERAL(12, 115, 13), // "setBrushColor"
QT_MOC_LITERAL(13, 129, 4), // "colr"
QT_MOC_LITERAL(14, 134, 11), // "setPenColor"
QT_MOC_LITERAL(15, 146, 8), // "clearAll"
QT_MOC_LITERAL(16, 155, 7), // "flipVer"
QT_MOC_LITERAL(17, 163, 7), // "flipHor"
QT_MOC_LITERAL(18, 171, 4), // "save"
QT_MOC_LITERAL(19, 176, 8), // "fileName"
QT_MOC_LITERAL(20, 185, 4), // "open"
QT_MOC_LITERAL(21, 190, 8), // "setSteps"
QT_MOC_LITERAL(22, 199, 2), // "st"
QT_MOC_LITERAL(23, 202, 9), // "setStartP"
QT_MOC_LITERAL(24, 212, 1) // "d"

    },
    "GScene\0setModeSelected\0\0setModeInsert\0"
    "setOpacity\0op\0setLineWidth\0lwidth\0"
    "setTypeEl\0setTypeZig\0setTypeSek\0"
    "deleteItem\0setBrushColor\0colr\0setPenColor\0"
    "clearAll\0flipVer\0flipHor\0save\0fileName\0"
    "open\0setSteps\0st\0setStartP\0d"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x0a /* Public */,
       4,    1,  101,    2, 0x0a /* Public */,
       6,    1,  104,    2, 0x0a /* Public */,
       8,    0,  107,    2, 0x0a /* Public */,
       9,    0,  108,    2, 0x0a /* Public */,
      10,    0,  109,    2, 0x0a /* Public */,
      11,    0,  110,    2, 0x0a /* Public */,
      12,    1,  111,    2, 0x0a /* Public */,
      14,    1,  114,    2, 0x0a /* Public */,
      15,    0,  117,    2, 0x0a /* Public */,
      16,    0,  118,    2, 0x0a /* Public */,
      17,    0,  119,    2, 0x0a /* Public */,
      18,    1,  120,    2, 0x0a /* Public */,
      20,    1,  123,    2, 0x0a /* Public */,
      21,    1,  126,    2, 0x0a /* Public */,
      23,    1,  129,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor,   13,
    QMetaType::Void, QMetaType::QColor,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::Int,   24,

       0        // eod
};

void GScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GScene *_t = static_cast<GScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setModeSelected(); break;
        case 1: _t->setModeInsert(); break;
        case 2: _t->setOpacity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setLineWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setTypeEl(); break;
        case 5: _t->setTypeZig(); break;
        case 6: _t->setTypeSek(); break;
        case 7: _t->deleteItem(); break;
        case 8: _t->setBrushColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 9: _t->setPenColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 10: _t->clearAll(); break;
        case 11: _t->flipVer(); break;
        case 12: _t->flipHor(); break;
        case 13: _t->save((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->open((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->setSteps((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->setStartP((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_GScene.data,
      qt_meta_data_GScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GScene.stringdata0))
        return static_cast<void*>(const_cast< GScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int GScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
