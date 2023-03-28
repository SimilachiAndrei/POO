#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:

	RangeRover();
	double getCap() const override;
	double getFuel() const override;
	double getSpeed(Weather cond) const override;

};