#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, x = 0;
	cin >> n >> x;

	vector<int> sequence;
	sequence.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		int number = 0;
		cin >> number;
		sequence.emplace_back(number);
	}

	for (const int& number : sequence)
	{
		if (number < x)
		{
			cout << number << " ";
		}
	}
}