#include "dataanalyse.h"
#include "ui_dataanalyse.h"

DataAnalyse::DataAnalyse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataAnalyse)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose, false);
    connect(ui->checkBoxList,&CheckBoxList::newCheckedBox,this,&DataAnalyse::dealChecked);
    connect(ui->checkBoxList,&CheckBoxList::newUncheckedBox,this,&DataAnalyse::dealUnchecked);
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&DataAnalyse::plotTime);
    drawInit();
}

DataAnalyse::~DataAnalyse()
{
    delete ui;
}

void DataAnalyse::setData(USV *_usv)
{
    this -> ui -> checkBoxList -> setData(_usv);
    this -> ui -> checkBoxList -> updateValue();
}

void DataAnalyse::dealChecked(NumCheckBox* newCheckedbox)
{
    numCheckedBoxs.append(newCheckedbox);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(QColor::fromHsl(rand()%360,rand()%256,rand()%200));
    this -> ui -> customplot -> addGraph();
    this -> ui -> customplot -> graph() -> setPen(pen);
    this -> ui -> customplot -> graph() -> setName(newCheckedbox->Name());
    if(!(timer->isActive()))
        timer->start(500);
}

void DataAnalyse::dealUnchecked(NumCheckBox* newCheckedbox)
{
    int deleteIndex =  numCheckedBoxs.indexOf(newCheckedbox);
    numCheckedBoxs.removeAt(deleteIndex);
    this -> ui -> customplot -> removeGraph(deleteIndex);
    if(numCheckedBoxs.length() == 0)
    {
        timer -> stop();
        this -> ui -> customplot -> replot();
    }
}

void DataAnalyse::drawInit()
{
    this -> ui -> customplot -> clearGraphs();

    this -> ui -> customplot -> legend -> setVisible(true);  //右上角添加曲线名称QPen(Qt::blue)
    this -> ui -> customplot -> legend -> setFont(QFont("Helvetica",10));
    this -> ui -> customplot -> axisRect() -> setupFullAxesBox();  //显示上边框和右边框
    this -> ui -> customplot -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    QSharedPointer<QCPAxisTickerTime> dateTicker(new QCPAxisTickerTime);
    dateTicker -> setTimeFormat("%h:%m:%s.%z");
    this -> ui -> customplot -> xAxis ->setTicker(dateTicker);
}

void DataAnalyse::plotTime()
{
    this->ui->checkBoxList->updateValue();
    double time = QTime::currentTime().msecsSinceStartOfDay()/1000.0;
    for(int i=0; i<numCheckedBoxs.length(); i++)
    {
        this -> ui -> customplot -> graph(i) -> addData(time,numCheckedBoxs.at(i)->Value());
        this -> ui -> customplot -> graph(i) -> data()->removeBefore(time-60);
        this -> ui -> customplot -> graph(i) -> rescaleValueAxis(true,true);
    }
    this -> ui -> customplot -> xAxis -> setRange(time-60,time);
    this -> ui -> customplot -> replot();
}
