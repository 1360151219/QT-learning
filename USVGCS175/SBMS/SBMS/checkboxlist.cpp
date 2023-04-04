#include "checkboxlist.h"
#include <QListWidgetItem>
#include <QCheckBox>
#include <QDebug>

CheckBoxList::CheckBoxList(QWidget *parent) : QListWidget(parent)
{
    for(int i=0; i<numCheckBoxNames.length(); i++)
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(300,47));
        NumCheckBox *numCheckBox = new NumCheckBox(numCheckBoxNames.at(i),this);
        this->addItem(item);
        this->setItemWidget(item,numCheckBox);
        m_allNumCheckBoxs.append(numCheckBox);
        connect(numCheckBox, &NumCheckBox::stateChanged, this, &CheckBoxList::anyStateChanged);
    }
}

void CheckBoxList::anyStateChanged(bool isChecked)
{
    NumCheckBox *changedNumCheckBox = qobject_cast<NumCheckBox *>(sender());
    if(isChecked)
    {
        //m_selectedNumCheckBoxs.append(changedNumCheckBox);
        emit newCheckedBox(changedNumCheckBox);
    }
    else
    {
        //m_selectedNumCheckBoxs.removeOne(changedNumCheckBox);
        emit newUncheckedBox(changedNumCheckBox);
    }
//    m_selectedNumCheckBoxs.clear();
//    for (int i=0; i<this->count(); i++) {
//        QListWidgetItem *item = this->item(i);
//        NumCheckBox *numCheckBox = static_cast<NumCheckBox *>(this->itemWidget(item));
//        if(numCheckBox->Checked())
//            m_selectedNumCheckBoxs.append(numCheckBox);
//    }
    //emit selectedNumCheckBoxsChanged(m_selectedNumCheckBoxs);
}

QList<NumCheckBox*> CheckBoxList::SelectedNumCheckBoxs() const
{
    return m_selectedNumCheckBoxs;
}

void CheckBoxList::setData(USV *_usv)
{
    usv = _usv;
}

void CheckBoxList::updateValue()
{
    m_allNumCheckBoxs[0]->setValue(usv->mode);
    m_allNumCheckBoxs[1]->setValue(usv->lng);
    m_allNumCheckBoxs[2]->setValue(usv->lat);
    m_allNumCheckBoxs[3]->setValue(static_cast<double>(usv->x));
    m_allNumCheckBoxs[4]->setValue(static_cast<double>(usv->y));
    m_allNumCheckBoxs[5]->setValue(static_cast<double>(usv->yaw));
    m_allNumCheckBoxs[6]->setValue(static_cast<double>(usv->pitch));
    m_allNumCheckBoxs[7]->setValue(static_cast<double>(usv->heel));
    m_allNumCheckBoxs[8]->setValue(static_cast<double>(usv->velocity));
    m_allNumCheckBoxs[9]->setValue(usv->thrust);
    m_allNumCheckBoxs[10]->setValue(usv->rudder);
    m_allNumCheckBoxs[11]->setValue(usv->progress);
    m_allNumCheckBoxs[12]->setValue(usv->satellite);
}

