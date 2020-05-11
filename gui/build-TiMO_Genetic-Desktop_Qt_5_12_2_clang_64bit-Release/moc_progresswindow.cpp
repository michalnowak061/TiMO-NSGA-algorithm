/****************************************************************************
** Meta object code from reading C++ file 'progresswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TiMO_Genetic/inc/progresswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'progresswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProgressWindow_t {
    QByteArrayData data[18];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProgressWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProgressWindow_t qt_meta_stringdata_ProgressWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ProgressWindow"
QT_MOC_LITERAL(1, 15, 14), // "Process_Cancel"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "Process_Stop"
QT_MOC_LITERAL(4, 44, 11), // "SetProgress"
QT_MOC_LITERAL(5, 56, 8), // "progress"
QT_MOC_LITERAL(6, 65, 1), // "t"
QT_MOC_LITERAL(7, 67, 1), // "T"
QT_MOC_LITERAL(8, 69, 20), // "SetPreviewPopulation"
QT_MOC_LITERAL(9, 90, 10), // "Population"
QT_MOC_LITERAL(10, 101, 1), // "P"
QT_MOC_LITERAL(11, 103, 11), // "Time_Update"
QT_MOC_LITERAL(12, 115, 10), // "Plot_Graph"
QT_MOC_LITERAL(13, 126, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(14, 148, 10), // "closeEvent"
QT_MOC_LITERAL(15, 159, 12), // "QCloseEvent*"
QT_MOC_LITERAL(16, 172, 5), // "event"
QT_MOC_LITERAL(17, 178, 26) // "on_Stop_pushButton_clicked"

    },
    "ProgressWindow\0Process_Cancel\0\0"
    "Process_Stop\0SetProgress\0progress\0t\0"
    "T\0SetPreviewPopulation\0Population\0P\0"
    "Time_Update\0Plot_Graph\0on_pushButton_clicked\0"
    "closeEvent\0QCloseEvent*\0event\0"
    "on_Stop_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProgressWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,   61,    2, 0x0a /* Public */,
       8,    1,   68,    2, 0x0a /* Public */,
      11,    0,   71,    2, 0x0a /* Public */,
      12,    0,   72,    2, 0x0a /* Public */,
      13,    0,   73,    2, 0x08 /* Private */,
      14,    1,   74,    2, 0x08 /* Private */,
      17,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,

       0        // eod
};

void ProgressWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProgressWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Process_Cancel(); break;
        case 1: _t->Process_Stop(); break;
        case 2: _t->SetProgress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->SetPreviewPopulation((*reinterpret_cast< Population(*)>(_a[1]))); break;
        case 4: _t->Time_Update(); break;
        case 5: _t->Plot_Graph(); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 8: _t->on_Stop_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProgressWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgressWindow::Process_Cancel)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProgressWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProgressWindow::Process_Stop)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProgressWindow::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_ProgressWindow.data,
    qt_meta_data_ProgressWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProgressWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProgressWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProgressWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ProgressWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ProgressWindow::Process_Cancel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ProgressWindow::Process_Stop()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
