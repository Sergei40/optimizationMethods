#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "gauss.h"
#include "ss.h"
#include "gaussmethod.h"
#include "simplex.h"
#include "steepascent.h"
#include "hook.h"
#include "nilder.h"
#include "analyticalanalysis.h"
#include <QSharedPointer>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_gauss_clicked();

    void on_simplex_clicked();

    void on_steepAscent_clicked();

    void on_hook_clicked();

    void on_nilder_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Gauss> gauss;
    std::shared_ptr<GaussMethod> gaussMethod;
    std::shared_ptr<Simplex> simplex;
    std::shared_ptr<SteepAscent> steepAscent;
    std::shared_ptr<Hook> hook;
    std::shared_ptr<Nilder> nilder;
    std::shared_ptr<AnalyticalAnalysis> analyticalAnalysis;
    QCustomPlot* qCustomPlot;
    QSharedPointer<ss> sss;
};
#endif // MAINWINDOW_H
