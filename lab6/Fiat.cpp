#include "Fiat.h"

Fiat::Fiat() :Car()
{
    name = "Fiat";
}
double Fiat::getCap()const
{
    return 30.0;
}
double Fiat::getFuel()const
{
    return 1.0;
}
double Fiat::getSpeed(Weather condition)const {
    switch (condition) {
    case Weather::Sunny:
        return 100.0;
    case Weather::Rain:
        return 70.0;
    case Weather::Snow:
        return 40.0;
    default:
        return 0.0;
    }
}
