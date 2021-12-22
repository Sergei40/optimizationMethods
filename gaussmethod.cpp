#include "gaussmethod.h"
#include "ui_gaussmethod.h"

GaussMethod::GaussMethod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GaussMethod)
{
    ui->setupUi(this);
    direction = 1;
    deltaX = 3.2;
    //inputData = std::make_shared<InputData>(25, 20, 0.15);
    //inputData = std::make_shared<InputData>(20, -30, 0.15);
    inputData = std::make_shared<InputData>(30, -5, 0.05);
    doMethod();
    qCustomPlot = new QCustomPlot;
    qCustomPlot->addGraph();
    QVector<double> funcPozitivX1;
    QVector<double> funcPozitivX2;
    QPen Pen1;
    Pen1.setColor(QColor(Qt::green));
    Pen1.setWidthF(2);//ширина линии

    for(double x1 = -50; x1 <= 50; x1 += 0.0001) {
        funcPozitivX1.append(x1);
        funcPozitivX2.append(inputData->x2ViaX1(x1, -25));
    }
    qCustomPlot->addGraph();
    qCustomPlot->graph(0)->setData(funcPozitivX1, funcPozitivX2);
    qCustomPlot->graph(0)->setPen(Pen1);
    funcPozitivX1.clear();
    funcPozitivX2.clear();
    for(double x1 = -50; x1 <= 50; x1 += 0.0001) {
        funcPozitivX1.append(x1);
        funcPozitivX2.append(inputData->x2ViaX1Negative(x1, -25));
    }
    qCustomPlot->addGraph();
    qCustomPlot->graph(1)->setData(funcPozitivX1, funcPozitivX2);
    qCustomPlot->graph(1)->setPen(Pen1);
    qCustomPlot->addGraph();
    qCustomPlot->graph(2)->setData({0.2, 0.2}, {-5, 10});
    qCustomPlot->graph(2)->setPen(Pen1);
    qCustomPlot->addGraph();
    qCustomPlot->graph(3)->setData(allX1, allX2);
    qCustomPlot->graph(3)->setLineStyle(QCPGraph::lsLine);
    ui->gridLayout->addWidget(qCustomPlot);
    qCustomPlot->xAxis->setLabel("x1");
    qCustomPlot->yAxis->setLabel("x2");
    qCustomPlot->xAxis->setRange(-100, 100);
    qCustomPlot->yAxis->setRange(-100, 100);
    qCustomPlot->replot();
    // sergei

    //inputData = std::make_shared<InputData>(20, -30, 0.15);
    //яна
    //inputData = std::make_shared<InputData>(30, -5, 0.05);
    //inputData = std::make_shared<InputData>(0, 100, 0.05);

    //ui->add
}

GaussMethod::~GaussMethod()
{
    delete ui;
}

double GaussMethod::doMethod()
{
    double startF = inputData->calculateFunction(inputData->getStartX1(), inputData->getStartX2());
    allX1.append(inputData->getStartX1());
    allX2.append(inputData->getStartX2());
    double answer = doIterations(inputData->getStartX1(), inputData->getStartX2(), startF);
    qDebug() << "answer: " << answer;
}

double GaussMethod::doIterations(double x1, double x2, double functionStartValue)
{
    //определяем значение в начальной точке
    if (deltaX <= inputData->getAccuracy()) {
        return functionStartValue;
    }
    qDebug() << QString("new Iteration: x1 = %1 x2 = %2 f = %3 delta = %4").arg(x1).arg(x2).arg(functionStartValue).arg(deltaX);
    //allX1.append(x1);
    //allX2.append(x2);
    double currentX1 = optimizeX1(x1, x2, functionStartValue);
    double currentFunction = inputData->calculateFunction(currentX1, x2);

    double currentX2 = optimizeX2(currentX1, x2, currentFunction);
    currentFunction = inputData->calculateFunction(currentX1, currentX2);

/*        allX1.append(currentX1);
        allX2.append(x2);

        allX1.append(currentX1)*/;

    if (currentFunction < functionStartValue) {
        doIterations(currentX1, currentX2, currentFunction);
    }
    else {
        deltaX = deltaX / 2;
        doIterations(currentX1, currentX2, currentFunction);
    }

}

double GaussMethod::optimizeX1(double x1, double x2, double functionStartValue)
{
    qDebug() << QString("optimize X1: x1 = %1 x2 = %2 f = %3").arg(x1).arg(x2).arg(inputData->calculateFunction(x1, x2));

    double currentFunctionValue = inputData->calculateFunction(x1 + direction * deltaX, x2);
    if (currentFunctionValue < functionStartValue) {
        optimizeX1(x1 + direction * deltaX, x2, currentFunctionValue);
    }
    else if (inputData->calculateFunction(x1 + (-direction * deltaX), x2) < functionStartValue){
        direction = -1 * direction;
        optimizeX1(x1 + (direction * deltaX), x2, functionStartValue);

    }
    else {
        allX1.append(x1);
       allX2.append(x2);
        return x1;

    }
}

double GaussMethod::optimizeX2(double x1, double x2, double functionStartValue)
{
    qDebug() << QString("optimize X2: x1 = %1 x2 = %2 f = %3").arg(x1).arg(x2).arg(inputData->calculateFunction(x1, x2));

    double currentFunctionValue = inputData->calculateFunction(x1, x2 + direction * deltaX);
    if (currentFunctionValue < functionStartValue) {
        optimizeX2(x1, x2 + direction * deltaX, currentFunctionValue);
    }
    else if (inputData->calculateFunction(x1, x2 + (-direction * deltaX)) < functionStartValue){
        direction = -1 * direction;
        optimizeX2(x1, x2 + (direction * deltaX), functionStartValue);

    }
    else {
        allX1.append(x1);
        allX2.append(x2);
        return x2;

    }
}
