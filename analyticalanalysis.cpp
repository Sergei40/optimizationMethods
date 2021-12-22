#include "analyticalanalysis.h"
#include "qcustomplot.h"

AnalyticalAnalysis::AnalyticalAnalysis(QObject *parent) : QObject(parent)
{

}

void AnalyticalAnalysis::calculateLevelsCoordinatesSergei()
{
    //150000
    for (int f = -700; f <= 3000; f+=10) {
        for(int x1 = -10; x1 <= 16; x1+=1) {
            double x2 = sqrt(f - pow(x1,3) + 16.5*pow(x1,2)) - x1;
            if (x2 != x2)
                continue;
            X2.append(x2);
            X1.append(x1);
        }
    }
}

void AnalyticalAnalysis::caluclateLevelsCoordinatesYana()
{
    for (int f = -1500; f <= 1500; f+=10) {
        for(int x1 = -200; x1 <= 200; x1+=10) {
            X2.append(sqrt(f - pow(x1,3) + 16.5*pow(x1,2)) - x1);
            X1.append(x1);
        }
    }
}

QVector<double> AnalyticalAnalysis::getX1()
{
    return X1;
}

QVector<double> AnalyticalAnalysis::getX2()
{
    return X2;
}
