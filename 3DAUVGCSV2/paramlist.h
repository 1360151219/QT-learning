#ifndef PARAMLIST_H
#define PARAMLIST_H

#include <QWidget>
#include "qmytableviewbtndelegate.h"
#include <QStandardItemModel>

namespace Ui {
class ParamList;
}

class ParamList : public QWidget
{
    Q_OBJECT

public:
    explicit ParamList(QWidget *parent = nullptr);
    ~ParamList();
    void updateSingleParam(uint8_t index,float param);

signals:
    void readSingleParam(uint8_t index);
    void setSingleParam(uint8_t index,float param);
    void readAllParam();
    void jsonListOpenFailed();

private slots:


    void on_lineEdit_table_search_textChanged(const QString &arg1);

    void on_pushButton_read_all_clicked();

    void on_pushButton_write_all_clicked();

    void on_pushButton_load_local_param_clicked();

    void on_pushButton_save_param_to_local_clicked();

private:
    Ui::ParamList *ui;

    QStandardItemModel *tableModel;
    QMyTableViewBtnDelegate *btnDelegate;
    void paramTableInit();
    void tableModelInit();
};

#endif // PARAMLIST_H
