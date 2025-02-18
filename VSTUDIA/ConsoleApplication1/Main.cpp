#include <iostream>

using namespace std;

double CalculatePrice(int Distance, double Fuel, double Price)
{
	double result;
	return result = (((Fuel / 100) * Distance) * Price)*2;
}

int main(void)
{
	int Distance;
	double FuelOn100Killometers;
	double PriceForLitr;
	cout << "Enter Distance to dacia: ";
	cin >> Distance;
	cout << "Enter using of fuel on 100 km: ";
	cin >> FuelOn100Killometers;
	cout << "Enter price for one litr of fuel: ";
	cin >> PriceForLitr;

	cout << "Going to dacia would cost u: " <<
		CalculatePrice(Distance, FuelOn100Killometers, PriceForLitr) << endl;

	return 0;
}