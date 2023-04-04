#ifndef DATAANALYSE_H
#define DATAANALYSE_H

#include <QWidget>
#include <numcheckbox.h>
#include <checkboxlist.h>
#include <QTimer>
#include "usv.h"
#include "qcustomplot.h"

namespace Ui {
class DataAnalyse;
}

class DataAnalyse : public QWidget
{
    Q_OBJECT

public:
    explicit DataAnalyse(QWidget *parent = nullptr);
    ~DataAnalyse();
    void setData(USV *_usv);

private slots:
    void dealChecked(NumCheckBox* newCheckedbox);
    void dealUnchecked(NumCheckBox* newCheckedbox);
    void plotTime();

private:
    Ui::DataAnalyse *ui;
    USV *usv;
    QList<NumCheckBox *> numCheckedBoxs;
    QTimer *timer;
    void drawInit();
};

#endif // DATAANALYSE_H
