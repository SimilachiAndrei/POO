#pragma once
#include "Car.h"
class Seat : public Car
{
public:

	Seat();
	double getCap() const override;
	double getFuel() const override;
	double getSpeed(Weather cond) const override;


};