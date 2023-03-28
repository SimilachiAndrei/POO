#pragma once
#include "Car.h"
#include <vector>
class Circuit
{
	int length;
	Weather cond;
	vector<Car*> cars;
public:
	void SetLength(int len);
	void SetWeather(Weather wt);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};