#pragma once
#include "Car.h"
class Volvo : public Car
{
public:

	Volvo();
	double getCap() const override;
	double getFuel() const override;
	double getSpeed(Weather cond) const override;

};