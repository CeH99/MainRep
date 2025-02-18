#include <iostream>

float Calculate(float purchases, float discount)
{
	float result;
	if (discount == 0)
		return purchases;
	
	return result = purchases - (purchases * discount / 100);
}

int main(void)
{
	float purchases = 0;
	float discount = 0;

	std::cout << "Enter summ of purchases: ";
	std::cin >> purchases;

	if (purchases > 1000) {
		discount = 5;
		std::cout << "Your discount is 5%" << "\n";
	}
	else if(purchases > 500) {
		discount = 3;
		std::cout << "Your discount is 3%" << "\n";
	}
	else
		std::cout << "You have no discount" << "\n";

	std::cout << "Price with your discount: " << Calculate(purchases, discount) << "\n";

	return 0;
}