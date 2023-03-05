/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../3DAUVGCSV2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[35];
    char stringdata0[1040];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "showTcpError"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(4, 54, 11), // "socketError"
QT_MOC_LITERAL(5, 66, 10), // "usvTcpRead"
QT_MOC_LITERAL(6, 77, 13), // "usvSerialRead"
QT_MOC_LITERAL(7, 91, 33), // "on_pushButton_tcp_connect_cli..."
QT_MOC_LITERAL(8, 125, 36), // "on_comboBox_mode_currentIndex..."
QT_MOC_LITERAL(9, 162, 5), // "index"
QT_MOC_LITERAL(10, 168, 30), // "on_pushButton_usv_init_clicked"
QT_MOC_LITERAL(11, 199, 31), // "on_pushButton_task_work_clicked"
QT_MOC_LITERAL(12, 231, 40), // "on_pushButton_read_control_pa..."
QT_MOC_LITERAL(13, 272, 39), // "on_pushButton_set_control_par..."
QT_MOC_LITERAL(14, 312, 36), // "on_pushButton_read_mid_param_..."
QT_MOC_LITERAL(15, 349, 35), // "on_pushButton_set_mid_param_c..."
QT_MOC_LITERAL(16, 385, 36), // "on_pushButton_serial_connect_..."
QT_MOC_LITERAL(17, 422, 35), // "on_pushButton_search_serial_c..."
QT_MOC_LITERAL(18, 458, 42), // "on_pushButton_query_control_c..."
QT_MOC_LITERAL(19, 501, 42), // "on_comboBox_los_select_curren..."
QT_MOC_LITERAL(20, 544, 30), // "on_pushButton_read_all_clicked"
QT_MOC_LITERAL(21, 575, 38), // "on_pushButton_load_local_para..."
QT_MOC_LITERAL(22, 614, 31), // "on_pushButton_write_all_clicked"
QT_MOC_LITERAL(23, 646, 41), // "on_pushButton_save_param_to_l..."
QT_MOC_LITERAL(24, 688, 36), // "on_lineEdit_table_search_text..."
QT_MOC_LITERAL(25, 725, 4), // "arg1"
QT_MOC_LITERAL(26, 730, 31), // "on_pushButton_add_point_clicked"
QT_MOC_LITERAL(27, 762, 36), // "on_pushButton_load_waypoints_..."
QT_MOC_LITERAL(28, 799, 28), // "on_pushButton_gohome_clicked"
QT_MOC_LITERAL(29, 828, 33), // "on_pushButton_usv_setHome_cli..."
QT_MOC_LITERAL(30, 862, 31), // "on_pushButton_load_task_clicked"
QT_MOC_LITERAL(31, 894, 54), // "on_comboBox_HeadingOrCourse_s..."
QT_MOC_LITERAL(32, 949, 23), // "changeStackedWidgetPage"
QT_MOC_LITERAL(33, 973, 31), // "on_btn_Rudder_returnMid_clicked"
QT_MOC_LITERAL(34, 1005, 34) // "on_btn_Propeller_returnMid_cl..."

    },
    "MainWindow\0showTcpError\0\0"
    "QAbstractSocket::SocketError\0socketError\0"
    "usvTcpRead\0usvSerialRead\0"
    "on_pushButton_tcp_connect_clicked\0"
    "on_comboBox_mode_currentIndexChanged\0"
    "index\0on_pushButton_usv_init_clicked\0"
    "on_pushButton_task_work_clicked\0"
    "on_pushButton_read_control_param_clicked\0"
    "on_pushButton_set_control_param_clicked\0"
    "on_pushButton_read_mid_param_clicked\0"
    "on_pushButton_set_mid_param_clicked\0"
    "on_pushButton_serial_connect_clicked\0"
    "on_pushButton_search_serial_clicked\0"
    "on_pushButton_query_control_config_clicked\0"
    "on_comboBox_los_select_currentIndexChanged\0"
    "on_pushButton_read_all_clicked\0"
    "on_pushButton_load_local_param_clicked\0"
    "on_pushButton_write_all_clicked\0"
    "on_pushButton_save_param_to_local_clicked\0"
    "on_lineEdit_table_search_textChanged\0"
    "arg1\0on_pushButton_add_point_clicked\0"
    "on_pushButton_load_waypoints_clicked\0"
    "on_pushButton_gohome_clicked\0"
    "on_pushButton_usv_setHome_clicked\0"
    "on_pushButton_load_task_clicked\0"
    "on_comboBox_HeadingOrCourse_select_currentIndexChanged\0"
    "changeStackedWidgetPage\0"
    "on_btn_Rudder_returnMid_clicked\0"
    "on_btn_Propeller_returnMid_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  159,    2, 0x08 /* Private */,
       5,    0,  162,    2, 0x08 /* Private */,
       6,    0,  163,    2, 0x08 /* Private */,
       7,    0,  164,    2, 0x08 /* Private */,
       8,    1,  165,    2, 0x08 /* Private */,
      10,    0,  168,    2, 0x08 /* Private */,
      11,    0,  169,    2, 0x08 /* Private */,
      12,    0,  170,    2, 0x08 /* Private */,
      13,    0,  171,    2, 0x08 /* Private */,
      14,    0,  172,    2, 0x08 /* Private */,
      15,    0,  173,    2, 0x08 /* Private */,
      16,    0,  174,    2, 0x08 /* Private */,
      17,    0,  175,    2, 0x08 /* Private */,
      18,    0,  176,    2, 0x08 /* Private */,
      19,    1,  177,    2, 0x08 /* Private */,
      20,    0,  180,    2, 0x08 /* Private */,
      21,    0,  181,    2, 0x08 /* Private */,
      22,    0,  182,    2, 0x08 /* Private */,
      23,    0,  183,    2, 0x08 /* Private */,
      24,    1,  184,    2, 0x08 /* Private */,
      26,    0,  187,    2, 0x08 /* Private */,
      27,    0,  188,    2, 0x08 /* Private */,
      28,    0,  189,    2, 0x08 /* Private */,
      29,    0,  190,    2, 0x08 /* Private */,
      30,    0,  191,    2, 0x08 /* Private */,
      31,    1,  192,    2, 0x08 /* Private */,
      32,    1,  195,    2, 0x08 /* Private */,
      33,    0,  198,    2, 0x08 /* Private */,
      34,    0,  199,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showTcpError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 1: _t->usvTcpRead(); break;
        case 2: _t->usvSerialRead(); break;
        case 3: _t->on_pushButton_tcp_connect_clicked(); break;
        case 4: _t->on_comboBox_mode_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_usv_init_clicked(); break;
        case 6: _t->on_pushButton_task_work_clicked(); break;
        case 7: _t->on_pushButton_read_control_param_clicked(); break;
        case 8: _t->on_pushButton_set_control_param_clicked(); break;
        case 9: _t->on_pushButton_read_mid_param_clicked(); break;
        case 10: _t->on_pushButton_set_mid_param_clicked(); break;
        case 11: _t->on_pushButton_serial_connect_clicked(); break;
        case 12: _t->on_pushButton_search_serial_clicked(); break;
        case 13: _t->on_pushButton_query_control_config_clicked(); break;
        case 14: _t->on_comboBox_los_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_pushButton_read_all_clicked(); break;
        case 16: _t->on_pushButton_load_local_param_clicked(); break;
        case 17: _t->on_pushButton_write_all_clicked(); break;
        case 18: _t->on_pushButton_save_param_to_local_clicked(); break;
        case 19: _t->on_lineEdit_table_search_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->on_pushButton_add_point_clicked(); break;
        case 21: _t->on_pushButton_load_waypoints_clicked(); break;
        case 22: _t->on_pushButton_gohome_clicked(); break;
        case 23: _t->on_pushButton_usv_setHome_clicked(); break;
        case 24: _t->on_pushButton_load_task_clicked(); break;
        case 25: _t->on_comboBox_HeadingOrCourse_select_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->changeStackedWidgetPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_btn_Rudder_returnMid_clicked(); break;
        case 28: _t->on_btn_Propeller_returnMid_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
