#include <iostream>
using namespace std;

int main()
{
	const int numberSize = 5;
	int numbers[numberSize];
	for (int i = 0; i < numberSize; ++i)
	{
		cin >> numbers[i];
	}

	int result = 0;
	for (int i = 0; i < numberSize; ++i)
	{
		result += numbers[i] * numbers[i];
	}
	
	cout << result % 10;
}