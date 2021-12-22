#ifndef GAUSSMETHOD_H
#define GAUSSMETHOD_H

#include <QWidget>
#include "qcustomplot.h"
#include "inputdata.h"
#include <memory>

namespace Ui {
class GaussMethod;
}

class GaussMethod : public QWidget
{
    Q_OBJECT

public:
    explicit GaussMethod(QWidget *parent = nullptr);
    ~GaussMethod();
    double doMethod();
    double doIterations(double x1, double x2, double functionStartValue);
    double optimizeX1(double x1, double x2, double functionValue);
    double optimizeX2(double x1, double x2, double startFunctionValue);
private:
    Ui::GaussMethod *ui;
    QCustomPlot* qCustomPlot;
    std::shared_ptr<InputData> inputData;
    double deltaX;
    int direction;
    QVector<double> allX1;
    QVector<double> allX2;
};

#endif // GAUSSMETHOD_H
