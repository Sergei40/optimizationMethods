#ifndef ANALYTICALANALYSIS_H
#define ANALYTICALANALYSIS_H

#include <QObject>

class AnalyticalAnalysis : public QObject
{
    Q_OBJECT
public:
    explicit AnalyticalAnalysis(QObject *parent = nullptr);
    void calculateLevelsCoordinatesSergei();
    void caluclateLevelsCoordinatesYana();
    QVector<double> getX1();
    QVector<double> getX2();
signals:

private:
    QVector<double> X1, X2;
    int fSergey;  //занчение функции
    int fYana;
};

#endif // ANALYTICALANALYSIS_H
