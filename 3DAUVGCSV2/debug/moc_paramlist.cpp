/****************************************************************************
** Meta object code from reading C++ file 'paramlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../3DAUVGCSV2/paramlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paramlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ParamList_t {
    QByteArrayData data[15];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParamList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParamList_t qt_meta_stringdata_ParamList = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ParamList"
QT_MOC_LITERAL(1, 10, 15), // "readSingleParam"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "uint8_t"
QT_MOC_LITERAL(4, 35, 5), // "index"
QT_MOC_LITERAL(5, 41, 14), // "setSingleParam"
QT_MOC_LITERAL(6, 56, 5), // "param"
QT_MOC_LITERAL(7, 62, 12), // "readAllParam"
QT_MOC_LITERAL(8, 75, 18), // "jsonListOpenFailed"
QT_MOC_LITERAL(9, 94, 36), // "on_lineEdit_table_search_text..."
QT_MOC_LITERAL(10, 131, 4), // "arg1"
QT_MOC_LITERAL(11, 136, 30), // "on_pushButton_read_all_clicked"
QT_MOC_LITERAL(12, 167, 31), // "on_pushButton_write_all_clicked"
QT_MOC_LITERAL(13, 199, 38), // "on_pushButton_load_local_para..."
QT_MOC_LITERAL(14, 238, 41) // "on_pushButton_save_param_to_l..."

    },
    "ParamList\0readSingleParam\0\0uint8_t\0"
    "index\0setSingleParam\0param\0readAllParam\0"
    "jsonListOpenFailed\0"
    "on_lineEdit_table_search_textChanged\0"
    "arg1\0on_pushButton_read_all_clicked\0"
    "on_pushButton_write_all_clicked\0"
    "on_pushButton_load_local_param_clicked\0"
    "on_pushButton_save_param_to_local_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParamList[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    2,   62,    2, 0x06 /* Public */,
       7,    0,   67,    2, 0x06 /* Public */,
       8,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   69,    2, 0x08 /* Private */,
      11,    0,   72,    2, 0x08 /* Private */,
      12,    0,   73,    2, 0x08 /* Private */,
      13,    0,   74,    2, 0x08 /* Private */,
      14,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Float,    4,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ParamList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ParamList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readSingleParam((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 1: _t->setSingleParam((*reinterpret_cast< uint8_t(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 2: _t->readAllParam(); break;
        case 3: _t->jsonListOpenFailed(); break;
        case 4: _t->on_lineEdit_table_search_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_read_all_clicked(); break;
        case 6: _t->on_pushButton_write_all_clicked(); break;
        case 7: _t->on_pushButton_load_local_param_clicked(); break;
        case 8: _t->on_pushButton_save_param_to_local_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ParamList::*)(uint8_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParamList::readSingleParam)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ParamList::*)(uint8_t , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParamList::setSingleParam)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ParamList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParamList::readAllParam)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ParamList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ParamList::jsonListOpenFailed)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ParamList::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ParamList.data,
    qt_meta_data_ParamList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ParamList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParamList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ParamList.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ParamList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ParamList::readSingleParam(uint8_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ParamList::setSingleParam(uint8_t _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ParamList::readAllParam()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ParamList::jsonListOpenFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
