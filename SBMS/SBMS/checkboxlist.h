#ifndef CHECKBOXLIST_H
#define CHECKBOXLIST_H

#include <QObject>
#include <QListWidget>
#include <QStringList>
#include "numcheckbox.h"
#include "usv.h"

class CheckBoxList : public QListWidget
{
    Q_OBJECT
    Q_PROPERTY(QList<NumCheckBox*> selectedNumCheckBoxs READ SelectedNumCheckBoxs NOTIFY selectedNumCheckBoxsChanged)

public:
    explicit CheckBoxList(QWidget *parent = nullptr);
    QList<NumCheckBox*> SelectedNumCheckBoxs() const;
    void setData(USV *_usv);

Q_SIGNALS:
    void selectedNumCheckBoxsChanged(QList<NumCheckBox*> selectedNumCheckBoxs);
    void newCheckedBox(NumCheckBox* newCheckedbox);
    void newUncheckedBox(NumCheckBox* newCheckedbox);

private slots:
    void anyStateChanged(bool isChecked);

public slots:
    void updateValue();

private:
    QStringList numCheckBoxNames = {"模式", "经度/°", "纬度/°", "X/m", "Y/m", "Yaw/°", "Pitch/°", "Heel/°", "Velocity/m/s", "Thrust/%", "Rudder/°", "Progress", "Satellite"};
    QList<NumCheckBox*> m_allNumCheckBoxs;
    QList<NumCheckBox*> m_selectedNumCheckBoxs;
    USV *usv;
};

#endif // CHECKBOXLIST_H
