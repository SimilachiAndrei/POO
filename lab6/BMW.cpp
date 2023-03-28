#include "BMW.h"
BMW::BMW():Car()
{
    name = "BMW";
}
double BMW::getCap()const 
{
	return 100.0;
}
double BMW::getFuel()const
{
	return 0.06;
}
double BMW::getSpeed(Weather condition)const {
    switch (condition) {
    case Weather::Sunny:
        return 140.0;
    case Weather::Rain:
        return 100.0;
    case Weather::Snow:
        return 80.0;
    default:
        return 0.0;
    }
}

