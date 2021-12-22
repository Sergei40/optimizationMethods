#include "gauss.h"
#include "ui_gauss.h"

Gauss::Gauss(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gauss)
{
    ui->setupUi(this);
    this->setWindowTitle("метод Гаусса-Зейделя");
    qCustomPlot = new QCustomPlot;

    qCustomPlot->addGraph();
    qDebug() << "hi";
    analyticalAnalysis->calculateLevelsCoordinatesSergei();
    qDebug() << "dfasdf";
    //QVector<long double> x;
    qCustomPlot->graph(0)->setData(analyticalAnalysis->getX1(), analyticalAnalysis->getX2());
    ui->gridLayout->addWidget(qCustomPlot);
    qCustomPlot->xAxis->setLabel("x1");
    qCustomPlot->yAxis->setLabel("x2");
    qCustomPlot->xAxis->setRange(-400, 400);
    qCustomPlot->yAxis->setRange(-200, 800);
    qCustomPlot->replot();
    ui->gridLayout->addWidget(qCustomPlot);
}

Gauss::~Gauss()
{
    delete qCustomPlot;
    delete ui;
}

void Gauss::drawPlot()
{
    //ui->gridLayout->addWidget(qCustomPlot, 1, 0, 1, 1);
}
