#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<int> sequence(n, 0);
	for (int& number : sequence)
	{
		cin >> number;
	}

	int min = sequence.front(), max = sequence.front();
	for (const int& number : sequence)
	{
		if (number < min)
		{
			min = number;
		}

		if (number > max)
		{
			max = number;
		}
	}

	cout << min << " " << max;
}