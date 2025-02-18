#include <iostream>

int sum(int n)
{
	int number = 0;
	for (int i = 0; i != n*2 ;i++)
	{
		if(i % 2)
		number += (i+1);
	}
	n = number;
	return n;
}

int main(void)
{
	int number;
	std::cout << "Enter number for sum: ";
	std::cin >> number;

	std::cout << "Sum of these numbers is: " << sum(number);
	return 0;
}