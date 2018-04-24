/****************************************************************************
** Meta object code from reading C++ file 'OpenCV_Grab_dual.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../OpenCV_Grab_dual/OpenCV_Grab_dual.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenCV_Grab_dual.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OpenCV_Grab_dual_t {
    QByteArrayData data[16];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OpenCV_Grab_dual_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OpenCV_Grab_dual_t qt_meta_stringdata_OpenCV_Grab_dual = {
    {
QT_MOC_LITERAL(0, 0, 16), // "OpenCV_Grab_dual"
QT_MOC_LITERAL(1, 17, 12), // "received_img"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 3), // "img"
QT_MOC_LITERAL(4, 35, 3), // "Fps"
QT_MOC_LITERAL(5, 39, 14), // "received_img_2"
QT_MOC_LITERAL(6, 54, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(7, 78, 23), // "on_actionStop_triggered"
QT_MOC_LITERAL(8, 102, 25), // "on_actionRecord_triggered"
QT_MOC_LITERAL(9, 128, 27), // "on_actionSettings_triggered"
QT_MOC_LITERAL(10, 156, 24), // "on_actionColor_triggered"
QT_MOC_LITERAL(11, 181, 25), // "on_actionDelete_triggered"
QT_MOC_LITERAL(12, 207, 17), // "printStateChanged"
QT_MOC_LITERAL(13, 225, 19), // "label_doubleClicked"
QT_MOC_LITERAL(14, 245, 21), // "label_doubleClicked_2"
QT_MOC_LITERAL(15, 267, 13) // "dialog_closed"

    },
    "OpenCV_Grab_dual\0received_img\0\0img\0"
    "Fps\0received_img_2\0on_actionOpen_triggered\0"
    "on_actionStop_triggered\0"
    "on_actionRecord_triggered\0"
    "on_actionSettings_triggered\0"
    "on_actionColor_triggered\0"
    "on_actionDelete_triggered\0printStateChanged\0"
    "label_doubleClicked\0label_doubleClicked_2\0"
    "dialog_closed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OpenCV_Grab_dual[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x0a /* Public */,
       5,    2,   79,    2, 0x0a /* Public */,
       6,    0,   84,    2, 0x0a /* Public */,
       7,    0,   85,    2, 0x0a /* Public */,
       8,    0,   86,    2, 0x0a /* Public */,
       9,    0,   87,    2, 0x0a /* Public */,
      10,    0,   88,    2, 0x0a /* Public */,
      11,    0,   89,    2, 0x0a /* Public */,
      12,    1,   90,    2, 0x0a /* Public */,
      13,    0,   93,    2, 0x0a /* Public */,
      14,    0,   94,    2, 0x0a /* Public */,
      15,    0,   95,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QImage, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OpenCV_Grab_dual::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OpenCV_Grab_dual *_t = static_cast<OpenCV_Grab_dual *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->received_img((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->received_img_2((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->on_actionOpen_triggered(); break;
        case 3: _t->on_actionStop_triggered(); break;
        case 4: _t->on_actionRecord_triggered(); break;
        case 5: _t->on_actionSettings_triggered(); break;
        case 6: _t->on_actionColor_triggered(); break;
        case 7: _t->on_actionDelete_triggered(); break;
        case 8: _t->printStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->label_doubleClicked(); break;
        case 10: _t->label_doubleClicked_2(); break;
        case 11: _t->dialog_closed(); break;
        default: ;
        }
    }
}

const QMetaObject OpenCV_Grab_dual::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_OpenCV_Grab_dual.data,
      qt_meta_data_OpenCV_Grab_dual,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OpenCV_Grab_dual::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OpenCV_Grab_dual::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OpenCV_Grab_dual.stringdata0))
        return static_cast<void*>(const_cast< OpenCV_Grab_dual*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int OpenCV_Grab_dual::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
