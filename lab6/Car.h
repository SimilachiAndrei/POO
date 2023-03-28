#pragma once
#include <iostream>
#include "Weather.h"
using namespace std;

class Car
{
protected:const char* name;
	public:
	Car(){};
	virtual double getCap() const=0;
	virtual double getFuel() const=0; 
	virtual double getSpeed(Weather cond) const=0;
	string getName() { return name; }
};