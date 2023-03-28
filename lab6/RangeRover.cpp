#include "RangeRover.h"
RangeRover::RangeRover() :Car()
{
    name = "RangeRover";
}
double RangeRover::getCap()const
{
    return 80.0;
}
double RangeRover::getFuel()const
{
    return 0.09;
}
double RangeRover::getSpeed(Weather condition)const {
    switch (condition) {
    case Weather::Sunny:
        return 120.0;
    case Weather::Rain:
        return 100.0;
    case Weather::Snow:
        return 90.0;
    default:
        return 0.0;
    }
}
