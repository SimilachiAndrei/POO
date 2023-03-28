#pragma once
#include "Car.h"
class BMW : public Car
{
public:
	BMW();
	double getCap()const override;
    double getFuel()const override;
	double getSpeed(Weather cond) const override;
};