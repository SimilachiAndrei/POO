#pragma once
#include "Car.h"
class Fiat : public Car
{
public:

	Fiat();
	double getCap() const override;
	double getFuel() const override;
	double getSpeed(Weather cond) const override;

};