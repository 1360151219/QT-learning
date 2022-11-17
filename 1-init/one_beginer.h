#ifndef ONE_BEGINER_H
#define ONE_BEGINER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class One_beginer; }
QT_END_NAMESPACE

class One_beginer : public QWidget
{
    Q_OBJECT

public:
    One_beginer(QWidget *parent = nullptr);
    ~One_beginer();

private:
    Ui::One_beginer *ui;
};
#endif // ONE_BEGINER_H
