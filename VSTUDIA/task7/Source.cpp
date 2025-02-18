#include <iostream>

double Speed(double distance, double time)
{
	double speed;
	return speed = (distance/time)/60*3.6;

}

int main(void)
{
	double distance;
	double time;
	std::cout << "Enter distance: ";
	std::cin >> distance;

	std::cout << "Enter time: ";
	std::cin >> time;

	std::cout << "Your speed was: " << Speed(distance, time);

	return 0;
}