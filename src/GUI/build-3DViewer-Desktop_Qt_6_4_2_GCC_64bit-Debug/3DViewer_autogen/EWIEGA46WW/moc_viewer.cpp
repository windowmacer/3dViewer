/****************************************************************************
** Meta object code from reading C++ file 'viewer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../3DViewer/viewer.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
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
struct qt_meta_stringdata_viewer_t {
    uint offsetsAndSizes[14];
    char stringdata0[7];
    char stringdata1[33];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[9];
    char stringdata5[8];
    char stringdata6[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_viewer_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_viewer_t qt_meta_stringdata_viewer = {
    {
        QT_MOC_LITERAL(0, 6),  // "viewer"
        QT_MOC_LITERAL(7, 32),  // "on_pushButton_selectFile_clicked"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 6),  // "moving"
        QT_MOC_LITERAL(48, 8),  // "rotation"
        QT_MOC_LITERAL(57, 7),  // "scaling"
        QT_MOC_LITERAL(65, 21)   // "on_testButton_clicked"
    },
    "viewer",
    "on_pushButton_selectFile_clicked",
    "",
    "moving",
    "rotation",
    "scaling",
    "on_testButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_viewer[] = {

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
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject viewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_viewer.offsetsAndSizes,
    qt_meta_data_viewer,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_viewer_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<viewer, std::true_type>,
        // method 'on_pushButton_selectFile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moving'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rotation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scaling'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_testButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void viewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<viewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_selectFile_clicked(); break;
        case 1: _t->moving(); break;
        case 2: _t->rotation(); break;
        case 3: _t->scaling(); break;
        case 4: _t->on_testButton_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *viewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *viewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_viewer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int viewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
