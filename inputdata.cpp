#include "inputdata.h"
#include <cmath>

InputData::InputData(double startX1, double startX2, double accuracy)
{
    this->startX1 = startX1;
    this->startX2 = startX2;
    this->accuracy = accuracy;
}

double InputData::calculateFunction(double x1, double x2)
{
  //  double f = pow(x1,3) - 16.5 * pow(x1,2) + pow((x1 + x2), 2);
    double f = pow(x1,3) - 15 * pow(x1,2) - 288 * x1 + pow((4* x1 + x2), 2);
    return f;
}

double InputData::calculateX2(double x1, double functionValue)
{
    double x2 = sqrt(functionValue - pow(x1,3) + 16.5 * pow(x1, 2)) - x1;
    return x2;
}

double InputData::getStartX1()
{
    return startX1;
}

double InputData::getStartX2()
{
    return startX2;
}

double InputData::getAccuracy()
{
    return accuracy;
}

double InputData::x2ViaX1(double x1, double f)
{
    return 4 * x1 - sqrt(f - (pow(x1,3) - 15 * pow(x1, 2) - 288 * x1));
}

double InputData::x2ViaX1Negative(double x1, double f)
{
    return 4 * x1 - ( - sqrt(f - (pow(x1,3) - 15 * pow(x1, 2) - 288 * x1)));
}
