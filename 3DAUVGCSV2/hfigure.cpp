#include "hfigure.h"
#include "ui_hfigure.h"
#include <QDebug>

HFigure::HFigure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HFigure)
{
    ui->setupUi(this);
    this -> setAttribute(Qt::WA_QuitOnClose,false);
    this -> setAttribute(Qt::WA_DeleteOnClose);
}

HFigure::~HFigure()
{
    delete ui;
}

HFigure::HFigure(QVector<QCPCurveData> lnglatData, QVector<QCPCurveData> xyData, QVector<double> t, QVector<double> yaw, QVector<double> course, QVector<double> desiredYaw, QVector<double> rudder, QVector<double> ye, QVector<double> velocity, QWidget *parent):
    QWidget(parent),
    ui(new Ui::HFigure)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose,false);
    this -> setAttribute(Qt::WA_DeleteOnClose);

    this -> ui -> plot_lnglat -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_lnglat -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_lnglat -> xAxis -> setLabel("Lng/°");
    this -> ui -> plot_lnglat -> yAxis -> setLabel("Lat/°");
    track = new QCPCurve(this -> ui -> plot_lnglat -> xAxis, this -> ui -> plot_lnglat -> yAxis);
    track -> data() -> set(lnglatData);
    this -> ui -> plot_lnglat -> rescaleAxes();
    this -> ui -> plot_lnglat -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_lnglat -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer = new QCPItemTracer(this->ui->plot_lnglat);
    tracer -> setStyle(QCPItemTracer::tsPlus);
    tracer -> position -> setTypeX(QCPItemPosition::ptPlotCoords);
    tracer -> position -> setTypeY(QCPItemPosition::ptPlotCoords);
    tracer -> setSize(20);
    tracer -> setVisible(true);

    this -> ui -> plot_xy -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_xy -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_xy -> xAxis -> setLabel("Y/m");
    this -> ui -> plot_xy -> yAxis -> setLabel("X/m");
    xyTrack = new QCPCurve(this -> ui -> plot_xy -> xAxis, this -> ui -> plot_xy -> yAxis);
    xyTrack -> data() -> set(xyData);
    this -> ui -> plot_xy -> rescaleAxes();
    this -> ui -> plot_xy -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_xy -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    xyTracer = new QCPItemTracer(this->ui->plot_xy);
    xyTracer -> setStyle(QCPItemTracer::tsPlus);
    xyTracer -> position -> setTypeX(QCPItemPosition::ptPlotCoords);
    xyTracer -> position -> setTypeY(QCPItemPosition::ptPlotCoords);
    xyTracer -> setSize(20);
    xyTracer -> setVisible(true);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%m:%s");

    this -> ui -> plot_course -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_course -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_course -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_course -> yAxis -> setLabel("Angle/°");
    this -> ui -> plot_course -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_course -> legend -> setVisible(true);
    this -> ui -> plot_course -> legend -> setBrush(QBrush(QColor(255,255,255,0)));
    this -> ui -> plot_course -> legend -> setBorderPen(QPen(QColor(255,255,255,0)));
    this -> ui -> plot_course -> addGraph();
    this -> ui -> plot_course -> graph(0) -> setPen(QPen(Qt::blue));
    this -> ui -> plot_course -> graph(0) -> setName("Yaw");
    this -> ui -> plot_course -> graph(0) -> addData(t,yaw);
    this -> ui -> plot_course -> addGraph();
    this -> ui -> plot_course -> graph(1) -> setPen(QPen(Qt::green));
    this -> ui -> plot_course -> graph(1) -> setName("Course");
    this -> ui -> plot_course -> graph(1) -> addData(t,course);
    this -> ui -> plot_course -> addGraph();
    this -> ui -> plot_course -> graph(2) -> setPen(QPen(Qt::red));
    this -> ui -> plot_course -> graph(2) -> setName("Desired Yaw");
    this -> ui -> plot_course -> graph(2) -> addData(t,desiredYaw);
    this -> ui -> plot_course -> rescaleAxes();
    this -> ui -> plot_course -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_course -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer_course = new TracerPlus(ui->plot_course,ui->plot_course->graph(0));
    connect(ui -> plot_course,&QCustomPlot::mouseMove,this,&HFigure::showTracer);

    this -> ui -> plot_course_rudder -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_course_rudder -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_course_rudder -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_course_rudder -> yAxis -> setLabel("Rudder Angle/°");
    this -> ui -> plot_course_rudder -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_course_rudder -> legend -> setVisible(true);
    this -> ui -> plot_course_rudder -> legend -> setBrush(QBrush(QColor(255,255,255,0)));
    this -> ui -> plot_course_rudder -> legend -> setBorderPen(QPen(QColor(255,255,255,0)));
    this -> ui -> plot_course_rudder -> addGraph();
    this -> ui -> plot_course_rudder -> graph(0) -> setPen(QPen(Qt::red));
    this -> ui -> plot_course_rudder -> graph(0) -> setName("Rudder");
    this -> ui -> plot_course_rudder -> graph(0) -> addData(t,rudder);
    this -> ui -> plot_course_rudder -> rescaleAxes();
    this -> ui -> plot_course_rudder -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_course_rudder -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer_course_rudder = new TracerPlus(ui->plot_course_rudder,ui->plot_course_rudder->graph());
    connect(ui -> plot_course_rudder,&QCustomPlot::mouseMove,this,&HFigure::showTracer);

    this -> ui -> plot_ye -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_ye -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_ye -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_ye -> yAxis -> setLabel("Ye/m");
    this -> ui -> plot_ye -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_ye -> addGraph();
    this -> ui -> plot_ye -> graph(0) -> addData(t,ye);
    this -> ui -> plot_ye -> rescaleAxes();
    this -> ui -> plot_ye -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_ye -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer_ye = new TracerPlus(ui->plot_ye,ui->plot_ye->graph());
    connect(ui -> plot_ye,&QCustomPlot::mouseMove,this,&HFigure::showTracer);

    this -> ui -> plot_velocity -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_velocity -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_velocity -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_velocity -> yAxis -> setLabel("Velocity/kn");
    this -> ui -> plot_velocity -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_velocity -> addGraph();
    this -> ui -> plot_velocity -> graph(0) -> addData(t,velocity);
    this -> ui -> plot_velocity -> rescaleAxes();
    this -> ui -> plot_velocity -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_velocity -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer_velocity = new TracerPlus(ui->plot_velocity,ui->plot_velocity->graph());
    connect(ui -> plot_velocity,&QCustomPlot::mouseMove,this,&HFigure::showTracer);
}

void HFigure::showTracer(QMouseEvent *event)
{
    double x = ui -> plot_course -> xAxis -> pixelToCoord(event->pos().x());

    QSharedPointer<QCPGraphDataContainer> tmpContainer = ui -> plot_course ->graph(0)->data();
    //使用二分法快速查找所在点的索引
    int low = 0, high = tmpContainer->size();
    int middle = 0 ;
    while(high > low)
    {
        middle = (low + high) / 2;
        if(x < tmpContainer->constBegin()->mainKey() ||
                x > (tmpContainer->constEnd()-1)->mainKey())
            break;


        if(high - low <= 1)
        {
            if(x > (tmpContainer->constBegin() + middle)->mainKey())
                middle = high;
            else
                middle = low;
            break;
        }
        else{
            if(x == (tmpContainer->constBegin() + middle)->mainKey())
                break;

            if(x > (tmpContainer->constBegin() + middle)->mainKey())
            {
                low = middle;
            }
            else if(x < (tmpContainer->constBegin() + middle)->mainKey())
            {
                high = middle;
            }
        }
    }

    QSharedPointer<QCPCurveDataContainer> CurveDataContainer = track->data();
    tracer -> position -> setCoords(CurveDataContainer->at(middle)->mainKey(),CurveDataContainer->at(middle)->mainValue());
    ui -> plot_lnglat -> replot(QCustomPlot::rpQueuedReplot);
    QSharedPointer<QCPCurveDataContainer> xyCurveDataContainer = xyTrack->data();
    xyTracer -> position -> setCoords(xyCurveDataContainer->at(middle)->mainKey(),xyCurveDataContainer->at(middle)->mainValue());
    ui -> plot_xy -> replot(QCustomPlot::rpQueuedReplot);

    tracer_course -> updatePosition(x);
    ui -> plot_course->replot(QCustomPlot::rpQueuedReplot);
    tracer_course_rudder -> updatePosition(x);
    ui -> plot_course_rudder->replot(QCustomPlot::rpQueuedReplot);
    tracer_ye -> updatePosition(x);
    ui -> plot_ye->replot(QCustomPlot::rpQueuedReplot);
    tracer_velocity -> updatePosition(x);
    ui -> plot_velocity->replot(QCustomPlot::rpQueuedReplot);
}
