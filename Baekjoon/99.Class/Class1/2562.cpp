#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int size = 9;

	vector<int> sequence;
	sequence.reserve(size);
	for (int i = 0; i < size; ++i)
	{
		int number = 0;
		cin >> number;
		sequence.emplace_back(number);
	}

	int maxNumber = 0, maxIndex = 0, currentIndex = 0;
	for (const int& number : sequence)
	{
		if (maxNumber < number)
		{
			maxNumber = number;
			maxIndex = currentIndex;
		}

		++currentIndex;
	}

	cout << maxNumber << "\n";
	cout << maxIndex + 1;
}