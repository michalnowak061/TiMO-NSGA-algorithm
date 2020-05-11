/****************************************************************************
** Meta object code from reading C++ file 'paretowindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TiMO_Genetic/inc/paretowindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paretowindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ParetoWindow_t {
    QByteArrayData data[10];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParetoWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParetoWindow_t qt_meta_stringdata_ParetoWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ParetoWindow"
QT_MOC_LITERAL(1, 13, 14), // "Set_Population"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 18), // "vector<Population>"
QT_MOC_LITERAL(4, 48, 1), // "P"
QT_MOC_LITERAL(5, 50, 4), // "time"
QT_MOC_LITERAL(6, 55, 10), // "Plot_Graph"
QT_MOC_LITERAL(7, 66, 26), // "on_Save_pushButton_clicked"
QT_MOC_LITERAL(8, 93, 35), // "on_Previous_Step_pushButton_c..."
QT_MOC_LITERAL(9, 129, 31) // "on_Next_Step_pushButton_clicked"

    },
    "ParetoWindow\0Set_Population\0\0"
    "vector<Population>\0P\0time\0Plot_Graph\0"
    "on_Save_pushButton_clicked\0"
    "on_Previous_Step_pushButton_clicked\0"
    "on_Next_Step_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParetoWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x08 /* Private */,
       8,    0,   46,    2, 0x08 /* Private */,
       9,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ParetoWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ParetoWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Set_Population((*reinterpret_cast< vector<Population>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->Plot_Graph(); break;
        case 2: _t->on_Save_pushButton_clicked(); break;
        case 3: _t->on_Previous_Step_pushButton_clicked(); break;
        case 4: _t->on_Next_Step_pushButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ParetoWindow::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_ParetoWindow.data,
    qt_meta_data_ParetoWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ParetoWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParetoWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ParetoWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ParetoWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
