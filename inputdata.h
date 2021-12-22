#ifndef INPUTDATA_H
#define INPUTDATA_H


class InputData
{
public:
    InputData(double, double, double);
    double calculateFunction(double x1, double x2);
    double calculateX2(double x1, double functionValue);
    double getStartX1();
    double getStartX2();
    double getAccuracy();
    double x2ViaX1(double x1, double f);
    double x2ViaX1Negative(double x1, double f);
private:
    double startX1, startX2;
    double accuracy;
};

#endif // INPUTDATA_H
