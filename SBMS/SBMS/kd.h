#ifndef KD_H
#define KD_H

#include <QWidget>

namespace Ui {
class kd;
}

class kd : public QWidget
{
    Q_OBJECT

public:
    explicit kd(QWidget *parent = nullptr);
    ~kd();

private:
    Ui::kd *ui;
};

#endif // KD_H
