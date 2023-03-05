#include "tracerplus.h"

TracerPlus::TracerPlus(QCustomPlot *_plot, QCPGraph *_graph) : plot(_plot),
    graph(_graph),
    visible(true)
{
    if(plot)
    {
        tracer = new QCPItemTracer(plot);
        tracer -> setStyle(QCPItemTracer::tsCrosshair);
        tracer -> setInterpolating(false);
        tracer -> setPen(graph->pen());
        tracer -> setBrush(graph->pen().color());
        tracer -> setSize(10);
        tracer -> setGraph(graph);
        tracer -> position -> setTypeX(QCPItemPosition::ptPlotCoords);
        tracer -> position -> setTypeY(QCPItemPosition::ptPlotCoords);

        dlabel = new QCPItemText(plot);
        dlabel -> setLayer("overlay");
        dlabel -> setClipToAxisRect(false);
        dlabel -> setPadding(QMargins(2,2,2,2));
        dlabel -> position -> setParentAnchor(tracer->position);
        dlabel -> position -> setCoords(15,0);
        dlabel -> setFont(QFont("宋体",10));
        dlabel -> setBrush(QBrush(QColor(244, 244, 244, 150)));
        dlabel -> setPen(graph->pen());
        dlabel -> setPositionAlignment(Qt::AlignLeft|Qt::AlignVCenter);

        darrow = new QCPItemLine(plot);
        darrow -> setLayer("overlay");
        darrow -> setPen(graph->pen());
        darrow -> setClipToAxisRect(false);
        darrow -> setHead(QCPLineEnding::esSpikeArrow);
        darrow -> end -> setParentAnchor(tracer->position);
        darrow -> start -> setParentAnchor(dlabel->left);

        xlabel = new QCPItemText(plot);
        xlabel -> setLayer("overlay");
        xlabel -> setClipToAxisRect(false);
        xlabel -> setPadding(QMargins(2,2,2,2));
        xlabel -> position -> setParentAnchorX(tracer->position);
        xlabel -> position -> setTypeY(QCPItemPosition::ptAxisRectRatio);
        xlabel -> position -> setCoords(0,1);
        xlabel -> setFont(QFont("宋体",10));
        xlabel -> setBrush(QBrush(QColor(244, 244, 244, 150)));
        xlabel -> setPen(graph->pen());
        xlabel -> setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);

        xarrow = new QCPItemLine(plot);
        xarrow -> setLayer("overlay");
        xarrow -> setPen(graph->pen());
        xarrow -> setClipToAxisRect(false);
        xarrow -> end -> setParentAnchor(tracer->position);
        xarrow -> start -> setParentAnchor(xlabel->top);

        setVisible(visible);
    }
}

TracerPlus::~TracerPlus()
{
    if(tracer)
        plot -> removeItem(tracer);
    if(dlabel)
        plot -> removeItem(dlabel);
    if(darrow)
        plot -> removeItem(darrow);
}

void TracerPlus::setPen(const QPen &pen)
{
    tracer -> setPen(pen);
    darrow -> setPen(pen);
}

void TracerPlus::setBrush(const QBrush &brush)
{
    tracer -> setBrush(brush);
}

void TracerPlus::setLabelPen(const QPen &pen)
{
    dlabel -> setPen(pen);
}

void TracerPlus::setText(const QString &text)
{
    dlabel -> setText(text);
}

void TracerPlus::setVisible(bool visible)
{
    tracer->setVisible(visible);
    dlabel->setVisible(visible);
    darrow->setVisible(visible);
}

void TracerPlus::updatePosition(double xValue)
{
    if(visible)
    {
        tracer->setGraphKey(xValue);
        dlabel->setText(QString::number(tracer->position->value(), 'f', 2));
        //xlabel->setText(QString::number(tracer->position->key(), 'f', 2));
        xlabel->setText(QTime::fromMSecsSinceStartOfDay(tracer->position->key()*1000).toString("mm:ss"));
    }
}
