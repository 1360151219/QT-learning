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

MFigure::MFigure(QVector<QCPCurveData> lnglatData, QVector<QCPCurveData> xyData, QVector<double> t, QVector<double> depth, QVector<double> desiredDepth, QVector<double> height, QVector<double> yaw, QVector<double> course, QVector<double> desiredYaw, QVector<double> pitch, QVector<double> desiredPitch, QVector<double> heel, QVector<double> ye, QVector<double> rudder, QVector<double> elevator,  QVector<double> velocity, QVector<double> alpha, QVector<double> beta, QWidget *parent):
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
    QCPCurve *track = new QCPCurve(this -> ui -> plot_lnglat -> xAxis, this -> ui -> plot_lnglat -> yAxis);
    track -> data() -> set(lnglatData);
    this -> ui -> plot_lnglat -> rescaleAxes();
    this -> ui -> plot_lnglat -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_lnglat -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    this -> ui -> plot_xy -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_xy -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_xy -> xAxis -> setLabel("Y/m");
    this -> ui -> plot_xy -> yAxis -> setLabel("X/m");
    QCPCurve *xyTrack = new QCPCurve(this -> ui -> plot_xy -> xAxis, this -> ui -> plot_xy -> yAxis);
    xyTrack -> data() -> set(xyData);
    this -> ui -> plot_xy -> rescaleAxes();
    this -> ui -> plot_xy -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_xy -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker -> setTimeFormat("%m:%s");

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
    this -> ui -> plot_depth -> graph(1) -> setPen(QPen(Qt::blue));
    this -> ui -> plot_depth -> graph(1) -> setName("Desired Depth");
    this -> ui -> plot_depth -> graph(1) -> addData(t,desiredDepth);
    this -> ui -> plot_depth -> rescaleAxes();
    this -> ui -> plot_depth -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_depth -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

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

    this -> ui -> plot_alpha_beta -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_alpha_beta -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_alpha_beta -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_alpha_beta -> yAxis -> setLabel("Angle/°");
    this -> ui -> plot_alpha_beta -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_alpha_beta -> legend -> setVisible(true);
    this -> ui -> plot_alpha_beta -> legend -> setBrush(QBrush(QColor(255,255,255,0)));
    this -> ui -> plot_alpha_beta -> legend -> setBorderPen(QPen(QColor(255,255,255,0)));
    this -> ui -> plot_alpha_beta -> addGraph();
    this -> ui -> plot_alpha_beta -> graph(0) -> setPen(QPen(Qt::blue));
    this -> ui -> plot_alpha_beta -> graph(0) -> setName("Alpha");
    this -> ui -> plot_alpha_beta -> graph(0) -> addData(t,alpha);
    this -> ui -> plot_alpha_beta -> addGraph();
    this -> ui -> plot_alpha_beta -> graph(1) -> setPen(QPen(Qt::red));
    this -> ui -> plot_alpha_beta -> graph(1) -> setName("Beta");
    this -> ui -> plot_alpha_beta -> graph(1) -> addData(t,beta);
    this -> ui -> plot_alpha_beta -> rescaleAxes();
    this -> ui -> plot_alpha_beta -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_alpha_beta -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

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

    this -> ui -> plot_elevator -> xAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_elevator -> yAxis -> setLabelFont(QFont("Helvetica",11));
    this -> ui -> plot_elevator -> xAxis -> setLabel("Time/s");
    this -> ui -> plot_elevator -> yAxis -> setLabel("Elevator/°");
    this -> ui -> plot_elevator -> xAxis -> setTicker(timeTicker);
    this -> ui -> plot_elevator -> addGraph();
    this -> ui -> plot_elevator -> graph(0) -> addData(t,elevator);
    this -> ui -> plot_elevator -> rescaleAxes();
    this -> ui -> plot_elevator -> axisRect() -> setupFullAxesBox();
    this -> ui -> plot_elevator -> setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

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
}
