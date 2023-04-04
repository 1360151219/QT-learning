#include "mfigure.h"
#include "ui_mfigure.h"

MFigure::MFigure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MFigure)
{
    ui->setupUi(this);
    this -> setAttribute(Qt::WA_QuitOnClose,false);
    this -> setAttribute(Qt::WA_DeleteOnClose);
}

MFigure::~MFigure()
{
    delete ui;
}

MFigure::MFigure(QVector<QCPCurveData> lnglatData, QVector<QCPCurveData> xyData, QVector<double> t, QVector<double> yaw, QVector<double> pitch, QVector<double> heel, QVector<double> velocity, QVector<double> thrust, QVector<double> rudder, QVector<double> progress, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MFigure)
{
    ui->setupUi(this);
    this -> setAttribute(Qt::WA_QuitOnClose,false);
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
    tracer -> setVisible(false);

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
    xyTracer -> setVisible(false);

    this -> ui -> plot_yaw -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_yaw -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_yaw -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_yaw -> yAxis -> setLabel("Yaw/°");
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker -> setTimeFormat("%m:%s");
    this -> ui -> plot_yaw -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_yaw -> addGraph();
    this -> ui -> plot_yaw -> graph(0) -> addData(t,yaw);
    this -> ui -> plot_yaw -> rescaleAxes();
    this -> ui -> plot_yaw -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_yaw -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer_yaw = new TracerPlus(ui->plot_yaw,ui->plot_yaw->graph());
    //connect(ui -> plot_yaw,&QCustomPlot::mouseMove,this,&MFigure::showTracer);

    this -> ui -> plot_heel -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_heel -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_heel -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_heel -> yAxis -> setLabel("Heel/°");
    this -> ui -> plot_heel -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_heel -> addGraph();
    this -> ui -> plot_heel -> graph(0) -> addData(t,heel);
    this -> ui -> plot_heel -> rescaleAxes();
    this -> ui -> plot_heel -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_heel -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer_heel = new TracerPlus(ui->plot_heel,ui->plot_heel->graph());
    //connect(ui -> plot_heel,&QCustomPlot::mouseMove,this,&MFigure::showTracer);

    this -> ui -> plot_pitch -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_pitch -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_pitch -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_pitch -> yAxis -> setLabel("Pitch/°");
    this -> ui -> plot_pitch -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_pitch -> addGraph();
    this -> ui -> plot_pitch -> graph(0) -> addData(t,pitch);
    this -> ui -> plot_pitch -> rescaleAxes();
    this -> ui -> plot_pitch -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_pitch -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer_pitch = new TracerPlus(ui->plot_pitch,ui->plot_pitch->graph());
    //connect(ui -> plot_pitch,&QCustomPlot::mouseMove,this,&MFigure::showTracer);

    this -> ui -> plot_velocity -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_velocity -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_velocity -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_velocity -> yAxis -> setLabel("Velocity/m/s");
    this -> ui -> plot_velocity -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_velocity -> addGraph();
    this -> ui -> plot_velocity -> graph(0) -> addData(t,velocity);
    this -> ui -> plot_velocity -> rescaleAxes();
    this -> ui -> plot_velocity -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_velocity -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer_velocity = new TracerPlus(ui->plot_velocity,ui->plot_velocity->graph());
    //connect(ui -> plot_velocity,&QCustomPlot::mouseMove,this,&MFigure::showTracer);

    this -> ui -> plot_thrust -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_thrust -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_thrust -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_thrust -> yAxis -> setLabel("Thrust/%");
    this -> ui -> plot_thrust -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_thrust -> addGraph();
    this -> ui -> plot_thrust -> graph(0) -> addData(t,thrust);
    this -> ui -> plot_thrust -> rescaleAxes();
    this -> ui -> plot_thrust -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_thrust -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer_thrust = new TracerPlus(ui->plot_thrust,ui->plot_thrust->graph());
    //connect(ui -> plot_thrust,&QCustomPlot::mouseMove,this,&MFigure::showTracer);

    this -> ui -> plot_rudder -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_rudder -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_rudder -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_rudder -> yAxis -> setLabel("Rudder/°");
    this -> ui -> plot_rudder -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_rudder -> addGraph();
    this -> ui -> plot_rudder -> graph(0) -> addData(t,rudder);
    this -> ui -> plot_rudder -> rescaleAxes();
    this -> ui -> plot_rudder -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_rudder -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer_rudder = new TracerPlus(ui->plot_rudder,ui->plot_rudder->graph());
    //connect(ui -> plot_rudder,&QCustomPlot::mouseMove,this,&MFigure::showTracer);

    this -> ui -> plot_progress -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_progress -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_progress -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_progress -> yAxis -> setLabel("Progress");
    this -> ui -> plot_progress -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_progress -> addGraph();
    this -> ui -> plot_progress -> graph(0) -> addData(t,progress);
    this -> ui -> plot_progress -> rescaleAxes();
    this -> ui -> plot_progress -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_progress -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tracer_progress = new TracerPlus(ui->plot_progress,ui->plot_progress->graph());
    //connect(ui -> plot_progress,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
}

void MFigure::showTracer(QMouseEvent *event)
{
    double x = ui -> plot_yaw -> xAxis -> pixelToCoord(event->pos().x());

    QSharedPointer<QCPGraphDataContainer> tmpContainer = ui -> plot_yaw ->graph(0)->data();
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

    tracer_yaw -> updatePosition(x);
    ui -> plot_yaw->replot(QCustomPlot::rpQueuedReplot);
    tracer_heel -> updatePosition(x);
    ui -> plot_heel->replot(QCustomPlot::rpQueuedReplot);
    tracer_pitch -> updatePosition(x);
    ui -> plot_pitch->replot(QCustomPlot::rpQueuedReplot);
    tracer_velocity -> updatePosition(x);
    ui -> plot_velocity->replot(QCustomPlot::rpQueuedReplot);
    tracer_thrust -> updatePosition(x);
    ui -> plot_thrust->replot(QCustomPlot::rpQueuedReplot);
    tracer_rudder -> updatePosition(x);
    ui -> plot_rudder->replot(QCustomPlot::rpQueuedReplot);
    tracer_progress -> updatePosition(x);
    ui -> plot_progress->replot(QCustomPlot::rpQueuedReplot);
}

void MFigure::setTracerVisible(bool visible)
{
    if(visible)
    {
        tracer -> setVisible(true);
        xyTracer -> setVisible(true);
        tracer_yaw -> setVisible(true);
        connect(ui -> plot_yaw,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_heel -> setVisible(true);
        connect(ui -> plot_heel,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_pitch -> setVisible(true);
        connect(ui -> plot_pitch,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_velocity -> setVisible(true);
        connect(ui -> plot_velocity,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_thrust -> setVisible(true);
        connect(ui -> plot_thrust,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_rudder -> setVisible(true);
        connect(ui -> plot_rudder,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_progress -> setVisible(true);
        connect(ui -> plot_progress,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
    }else {
        tracer -> setVisible(false);
        xyTracer -> setVisible(false);
        tracer_yaw -> setVisible(false);
        disconnect(ui -> plot_yaw,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_heel -> setVisible(false);
        disconnect(ui -> plot_heel,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_pitch -> setVisible(false);
        disconnect(ui -> plot_pitch,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_velocity -> setVisible(false);
        disconnect(ui -> plot_velocity,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_thrust -> setVisible(false);
        disconnect(ui -> plot_thrust,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_rudder -> setVisible(false);
        disconnect(ui -> plot_rudder,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
        tracer_progress -> setVisible(false);
        disconnect(ui -> plot_progress,&QCustomPlot::mouseMove,this,&MFigure::showTracer);
    }
    ui -> plot_lnglat -> replot(QCustomPlot::rpQueuedReplot);
    ui -> plot_xy -> replot(QCustomPlot::rpQueuedReplot);
    ui -> plot_yaw->replot(QCustomPlot::rpQueuedReplot);
    ui -> plot_heel->replot(QCustomPlot::rpQueuedReplot);
    ui -> plot_pitch->replot(QCustomPlot::rpQueuedReplot);
    ui -> plot_velocity->replot(QCustomPlot::rpQueuedReplot);
    ui -> plot_thrust->replot(QCustomPlot::rpQueuedReplot);
    ui -> plot_rudder->replot(QCustomPlot::rpQueuedReplot);
    ui -> plot_progress->replot(QCustomPlot::rpQueuedReplot);
}
