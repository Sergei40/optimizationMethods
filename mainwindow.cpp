#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QApplication::setStyle("macos");
    this->setWindowTitle("методы безусловной оптимизации");
    this->analyticalAnalysis = std::make_shared<AnalyticalAnalysis>();
    this->qCustomPlot = new QCustomPlot;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_gauss_clicked()
{

//    ui->gridLayout->addWidget(qCustomPlot, 1, 0, 1, 1);
//    qCustomPlot->addGraph(qCustomPlot->xAxis, qCustomPlot->yAxis);
//    qDebug() << "hi";
//    analyticalAnalysis->calculateLevelsCoordinatesSergei();
//    qDebug() << "dfasdf";
//    qCustomPlot->graph(0)->setData(analyticalAnalysis->getX1(), analyticalAnalysis->getX2());
//    qCustomPlot->xAxis->setLabel("x1");
//    qCustomPlot->yAxis->setLabel("x2");
//    qCustomPlot->replot();
//    sss->u
    if (!gaussMethod) {
        gaussMethod = std::make_shared<GaussMethod>();
    }
    gaussMethod->show();
    gaussMethod->activateWindow();
}


void MainWindow::on_simplex_clicked()
{
    if (!simplex)
        simplex = std::make_shared<Simplex>();
    simplex->show();
    simplex->activateWindow();
}


void MainWindow::on_steepAscent_clicked()
{
    if (!steepAscent)
        steepAscent = std::make_shared<SteepAscent>();
    steepAscent->show();
    steepAscent->activateWindow();
}


void MainWindow::on_hook_clicked()
{
    if (!hook)
        hook = std::make_shared<Hook>();
    hook->show();
    hook->activateWindow();
}


void MainWindow::on_nilder_clicked()
{
    if (!nilder)
        nilder = std::make_shared<Nilder>();
    nilder->show();
    nilder->activateWindow();
}

