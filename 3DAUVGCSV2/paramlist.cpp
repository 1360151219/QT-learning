#include "paramlist.h"
#include "ui_paramlist.h"
#include <QDebug>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDir>

ParamList::ParamList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParamList)
{
    ui->setupUi(this);
}

ParamList::~ParamList()
{
    delete ui;
}

void ParamList::paramTableInit()
{
    // 必须要设置此项，否则样式表的hover无法生效
    this -> ui -> tableView->setMouseTracking(true);
    // 为指定列设置代理
    btnDelegate = new QMyTableViewBtnDelegate(QStringList()<<"Read"<<"Set", this);

    connect(btnDelegate, &QMyTableViewBtnDelegate::readData, this, [=](const QModelIndex &index){
        uint8_t paramIndex = static_cast<uint8_t>(tableModel->item(index.row(),0)->text().toUInt());
        emit readSingleParam(paramIndex);
    });
    connect(btnDelegate, &QMyTableViewBtnDelegate::setData, this, [=](const QModelIndex &index){
        uint8_t paramIndex = static_cast<uint8_t>(tableModel->item(index.row(),0)->text().toUInt());
        float param = tableModel->item(index.row(),2)->text().toFloat();
        emit setSingleParam(paramIndex,param);
    });

    this -> ui->tableView->setItemDelegateForColumn(3, btnDelegate);

    tableModel = new QStandardItemModel(this);
    this -> ui -> tableView ->setModel(tableModel);
    QStringList columnTitles;
    columnTitles << "Index" << "Name" << "Value" << "Action";
    tableModel->setHorizontalHeaderLabels(columnTitles);

    tableModelInit();
    this -> ui -> tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void ParamList::tableModelInit()
{
    QFile jsonFile(QDir::currentPath()+"/param/gcs_param/paramsList.json");
    if(!jsonFile.open(QIODevice::ReadOnly))
    {
        emit jsonListOpenFailed();
        //this -> ui -> statusBar -> showMessage("Json文件打开失败，请重试", 2000);
        return;
    }

    QJsonObject rootObj = QJsonDocument::fromJson(jsonFile.readAll()).object();
    jsonFile.close();

    int cnt = 1;
    while(1)
    {
        if(rootObj.contains(QString::number(cnt)))
        {
            if(rootObj.value(QString::number(cnt)).isObject())
            {
                QJsonObject paramObj = rootObj.value(QString::number(cnt)).toObject();
                QString paramName = paramObj.value("Name").toString();
                double paramValue = paramObj.value("Value").toDouble();
                tableModel->setItem(cnt-1,0,new QStandardItem(QString::number(cnt)));
                tableModel->setItem(cnt-1,1,new QStandardItem(paramName));
                tableModel->setItem(cnt-1,2,new QStandardItem(QString::number(paramValue)));
            }
            cnt++;
        }else
            break;
    }
}

void ParamList::on_lineEdit_table_search_textChanged(const QString &arg1)
{
    if(arg1=="")
    {
        for(int i=0;i<tableModel->rowCount();i++)
            ui->tableView->setRowHidden(i,false);
    }
    else
    {
        QString queryStr = this -> ui -> lineEdit_table_search -> text().remove(QRegExp("\\s"));
        for(int i=0;i<tableModel->rowCount();i++)
        {
            QString thisName = tableModel->item(i,1)->text().remove(QRegExp("\\s"));
            if(thisName.contains(queryStr))
                this->ui->tableView->setRowHidden(i,false);
            else
                this->ui->tableView->setRowHidden(i,true);
        }
    }
}

void ParamList::on_pushButton_read_all_clicked()
{
    emit readAllParam();
}

void ParamList::on_pushButton_write_all_clicked()
{
    int paramsCount = tableModel->rowCount();
    for(int i=0;i<paramsCount;i++)
    {
        uint8_t paramIndex = static_cast<uint8_t>(tableModel->item(i,0)->text().toUInt());
        float param = tableModel->item(i,2)->text().toFloat();
        emit setSingleParam(paramIndex,param);
    }
}

void ParamList::on_pushButton_load_local_param_clicked()
{
    tableModelInit();
}

void ParamList::on_pushButton_save_param_to_local_clicked()
{
    int paramsCount = tableModel->rowCount();
    QJsonObject rootObject;
    for(int i=0;i<paramsCount;i++)
    {
        QJsonObject paramObj;
        paramObj["Name"] = tableModel->item(i,1)->text();
        paramObj["Value"] = tableModel->item(i,2)->text().toDouble();
        rootObject[tableModel->item(i,0)->text()] = paramObj;
    }
    QFile file(QDir::currentPath()+"/param/gcs_param/paramsList.json");
    file.open(QIODevice::WriteOnly);
    file.write(QJsonDocument(rootObject).toJson());
    file.close();
}

void ParamList::updateSingleParam(uint8_t index,float param)
{
    tableModel->item(index-1,2)->setText(QString::number(static_cast<double>(param)));
}
