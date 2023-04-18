#ifndef NUMCHECKBOX_H
#define NUMCHECKBOX_H

#include <QObject>
#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QHBoxLayout>

class NumCheckBox : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(double value READ Value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString name READ Name WRITE setName)
    Q_PROPERTY(bool checked READ Checked NOTIFY stateChanged)

public:
    explicit NumCheckBox(QWidget *parent = nullptr);
    explicit NumCheckBox(QString name, QWidget *parent = nullptr);
    NumCheckBox(QString name, double value, QWidget *parent = nullptr);

Q_SIGNALS:
    void valueChanged(double value);
    void stateChanged(bool isChecked);

public:
    double Value() const;
    QString Name() const;
    bool Checked() const;

public Q_SLOTS:
    void setValue(double value);
    void setName(QString name);

private:
    double m_value;
    QString m_name;
    bool m_checked;
    QCheckBox *checkBox;
    QLabel *label;
};

#endif // NUMCHECKBOX_H
