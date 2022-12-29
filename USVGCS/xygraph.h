#ifndef XYGRAPH_H
#define XYGRAPH_H
#include <QSplineSeries>
#include <QDialog>
#include <QtCharts/QChart>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class xyGraph;
}

class xyGraph : public QDialog
{
    Q_OBJECT

public:
    explicit xyGraph(QWidget *parent = nullptr);
    ~xyGraph();

    void paint(QJsonArray &jsonArr);

private:
    Ui::xyGraph *ui;
    QSplineSeries* series;
};

#endif // XYGRAPH_H
