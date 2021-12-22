#ifndef GAUSS_H
#define GAUSS_H

#include <QDialog>
#include <analyticalanalysis.h>
#include "qcustomplot.h"

namespace Ui {
class Gauss;
}

class Gauss : public QDialog
{
    Q_OBJECT

public:
    explicit Gauss(QWidget *parent = nullptr);
    ~Gauss();
    void drawPlot();
private:
    Ui::Gauss *ui;
    QSharedPointer<AnalyticalAnalysis> analyticalAnalysis;
    QCustomPlot* qCustomPlot;
};

#endif // GAUSS_H
