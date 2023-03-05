#include "vfigure.h"
#include "ui_vfigure.h"

VFigure::VFigure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VFigure)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_QuitOnClose,false);
    this -> setAttribute(Qt::WA_DeleteOnClose);
}


VFigure::VFigure(QVector<double> t, QVector<double> depth, QVector<double> desiredDepth,QVector<double> height, QVector<double> pitch, QVector<double> desiredPitch, QVector<double> elevator, QVector<double> heel, QVector<double> heelReject, QVector<double> beta,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VFigure)
{
    ui->setupUi(this);
    this -> setAttribute(Qt::WA_QuitOnClose,false);
    this -> setAttribute(Qt::WA_DeleteOnClose);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%m:%s");

    this -> ui -> plot_depth -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_depth -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_depth -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_depth -> yAxis -> setLabel("Depth/m");
    this -> ui -> plot_depth -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_depth -> legend -> setVisible(true);
    this -> ui -> plot_depth -> legend -> setBrush(QBrush(QColor(255,255,255,0)));
    this -> ui -> plot_depth -> legend -> setBorderPen(QPen(QColor(255,255,255,0)));
    this -> ui -> plot_depth -> addGraph();
    this -> ui -> plot_depth -> graph(0) -> setPen(QPen(Qt::blue));
    this -> ui -> plot_depth -> graph(0) -> setName("Depth");
    this -> ui -> plot_depth -> graph(0) -> addData(t,depth);
    this -> ui -> plot_depth -> addGraph();
    this -> ui -> plot_depth -> graph(1) -> setPen(QPen(Qt::red));
    this -> ui -> plot_depth -> graph(1) -> setName("Desired Depth");
    this -> ui -> plot_depth -> graph(1) -> addData(t,desiredDepth);
    this -> ui -> plot_depth -> rescaleAxes();
    this -> ui -> plot_depth -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_depth -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    dpethTracer = new TracerPlus(ui->plot_depth,ui->plot_depth->graph(0));
    connect(ui -> plot_depth,&QCustomPlot::mouseMove,this,&VFigure::showTracer);

    this -> ui -> plot_height -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_height -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_height -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_height -> yAxis -> setLabel("Height/m");
    this -> ui -> plot_height -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_height -> addGraph();
    this -> ui -> plot_height -> graph(0) -> addData(t,height);
    this -> ui -> plot_height -> rescaleAxes();
    this -> ui -> plot_height -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_height -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    heightTracer = new TracerPlus(ui->plot_height,ui->plot_height->graph());
    connect(ui -> plot_height,&QCustomPlot::mouseMove,this,&VFigure::showTracer);

    this -> ui -> plot_pitch -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_pitch -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_pitch -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_pitch -> yAxis -> setLabel("Pitch/°");
    this -> ui -> plot_pitch -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_pitch -> legend -> setVisible(true);
    this -> ui -> plot_pitch -> legend -> setBrush(QBrush(QColor(255,255,255,0)));
    this -> ui -> plot_pitch -> legend -> setBorderPen(QPen(QColor(255,255,255,0)));
    this -> ui -> plot_pitch -> addGraph();
    this -> ui -> plot_pitch -> graph(0) -> setPen(QPen(Qt::blue));
    this -> ui -> plot_pitch -> graph(0) -> setName("Pitch");
    this -> ui -> plot_pitch -> graph(0) -> addData(t,pitch);
    this -> ui -> plot_pitch -> addGraph();
    this -> ui -> plot_pitch -> graph(1) -> setPen(QPen(Qt::red));
    this -> ui -> plot_pitch -> graph(1) -> setName("Desired Pitch");
    this -> ui -> plot_pitch -> graph(1) -> addData(t,desiredPitch);
    this -> ui -> plot_pitch -> rescaleAxes();
    this -> ui -> plot_pitch -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_pitch -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    pitchTracer = new TracerPlus(ui->plot_pitch,ui->plot_pitch->graph(0));
    connect(ui -> plot_pitch,&QCustomPlot::mouseMove,this,&VFigure::showTracer);

    this -> ui -> plot_stern_rudder -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_stern_rudder -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_stern_rudder -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_stern_rudder -> yAxis -> setLabel("Elevator/°");
    this -> ui -> plot_stern_rudder -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_stern_rudder -> addGraph();
    this -> ui -> plot_stern_rudder -> graph(0) -> addData(t,elevator);
    this -> ui -> plot_stern_rudder -> rescaleAxes();
    this -> ui -> plot_stern_rudder -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_stern_rudder -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    sternTracer = new TracerPlus(ui->plot_stern_rudder,ui->plot_stern_rudder->graph());
    connect(ui -> plot_stern_rudder,&QCustomPlot::mouseMove,this,&VFigure::showTracer);

    this -> ui -> plot_heel -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_heel -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_heel -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_heel -> yAxis -> setLabel("-");
    this -> ui -> plot_heel -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_heel -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_heel -> legend -> setVisible(true);
    this -> ui -> plot_heel -> legend -> setBrush(QBrush(QColor(255,255,255,0)));
    this -> ui -> plot_heel -> legend -> setBorderPen(QPen(QColor(255,255,255,0)));
    this -> ui -> plot_heel -> addGraph();
    this -> ui -> plot_heel -> graph(0) -> setPen(QPen(Qt::blue));
    this -> ui -> plot_heel -> graph(0) -> setName("Heel");
    this -> ui -> plot_heel -> graph(0) -> addData(t,heel);
    this -> ui -> plot_heel -> addGraph();
    this -> ui -> plot_heel -> graph(1) -> setPen(QPen(Qt::green));
    this -> ui -> plot_heel -> graph(1) -> setName("Heel Reject");
    this -> ui -> plot_heel -> graph(1) -> addData(t,heelReject);
    this -> ui -> plot_heel -> rescaleAxes();
    this -> ui -> plot_heel -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_heel -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    heelTracer = new TracerPlus(ui->plot_heel,ui->plot_heel->graph(0));
    connect(ui -> plot_heel,&QCustomPlot::mouseMove,this,&VFigure::showTracer);


    this -> ui -> plot_beta -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_beta -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_beta -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_beta -> yAxis -> setLabel("Beta/°");
    this -> ui -> plot_beta -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_beta -> addGraph();
    this -> ui -> plot_beta -> graph(0) -> addData(t,beta);
    this -> ui -> plot_beta -> rescaleAxes();
    this -> ui -> plot_beta -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_beta -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    bowTracer = new TracerPlus(ui->plot_beta,ui->plot_beta->graph());
    connect(ui -> plot_beta,&QCustomPlot::mouseMove,this,&VFigure::showTracer);
}

VFigure::~VFigure()
{
    delete ui;
}


void VFigure::showTracer(QMouseEvent *event)
{
    double x = ui -> plot_depth -> xAxis -> pixelToCoord(event->pos().x());

    dpethTracer -> updatePosition(x);
    ui -> plot_depth->replot(QCustomPlot::rpQueuedReplot);
    heightTracer -> updatePosition(x);
    ui -> plot_height->replot(QCustomPlot::rpQueuedReplot);
    pitchTracer -> updatePosition(x);
    ui -> plot_pitch->replot(QCustomPlot::rpQueuedReplot);
    sternTracer -> updatePosition(x);
    ui -> plot_stern_rudder->replot(QCustomPlot::rpQueuedReplot);
    bowTracer -> updatePosition(x);
    ui -> plot_beta->replot(QCustomPlot::rpQueuedReplot);
    heelTracer -> updatePosition(x);
    ui -> plot_heel->replot(QCustomPlot::rpQueuedReplot);
}
