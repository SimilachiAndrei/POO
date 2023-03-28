#include "Seat.h"
Seat::Seat() :Car()
{
    name = "Seat";
}
double Seat::getCap()const
{
    return 55.0;
}
double Seat::getFuel()const
{
    return 3.0;
}
double Seat::getSpeed(Weather condition)const {
    switch (condition) {
    case Weather::Sunny:
        return 110.0;
    case Weather::Rain:
        return 95.0;
    case Weather::Snow:
        return 40.0;
    default:
        return 0.0;
    }
}
