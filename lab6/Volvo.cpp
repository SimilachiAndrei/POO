#include "Volvo.h"
Volvo::Volvo() :Car()
{
    name = "Volvo";
}
double Volvo::getCap()const
{
    return 70.0;
}
double Volvo::getFuel()const
{
    return 0.6;
}
double Volvo::getSpeed(Weather condition)const {
    switch (condition) {
    case Weather::Sunny:
        return 121.0;
    case Weather::Rain:
        return 70.0;
    case Weather::Snow:
        return 60.0;
    default:
        return 0.0;
    }
}
