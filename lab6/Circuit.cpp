#include "Circuit.h"
#include <algorithm>
void Circuit::SetLength(int len)
{
	length = len;
}
void Circuit::SetWeather(Weather wv)
{
	cond = wv;
}
void Circuit::AddCar(Car* c)
{
	cars.push_back(c); 
}
void Circuit::Race() {
    cout << "Race: " << endl;
    for (int i = 0;i<cars.size();i++) {
        if (length*cars[i]->getFuel() > cars[i]->getCap()) {
            cout << cars[i]->getName() << " cannot finish the circuit." << std::endl;
        }
        else {
            cout <<cars[i]->getName() << " finished the circuit in " << length / cars[i]->getSpeed(cond) << " hours." << std::endl;
        }
    }
}

void Circuit::ShowFinalRanks()  {
    std::vector<std::pair<double, string>> results;
    std::vector<std::pair<double, string>> failures;
    for (auto car : cars) {
        if (length * car->getFuel() <= car->getCap()) {
            double time = length / car->getSpeed(cond);
            results.emplace_back(time, car->getName());
        }
        else
        {
            double kmStop = double(car->getCap() / car->getFuel());
            failures.emplace_back(kmStop, car->getName());
        }
    }
    sort(results.begin(), results.end());
    sort(failures.begin(), failures.end());
    cout << "Final Ranks:\n";
    for (auto result : results) {
        std::cout << "Car finished the circuit in " << result.first << " hours: " <<result.second << std::endl;
    }
    for (int i = failures.size() - 1; i >= 0; i--)
    {
        cout << failures[i].second<<" did not finish and stopped at km "<<failures[i].first<<endl;
    }
}
void Circuit::ShowWhoDidNotFinish() {
    cout << endl << "CarsWhoDidNotFinish:" << endl;
    for (auto car : cars) {
        double fuel_required = length * car->getFuel() / car->getSpeed(cond);
        if (length * car->getFuel() > car->getCap()) {
            std::cout << car->getName() << " did not finish the circuit." << std::endl;
        }
    }
}