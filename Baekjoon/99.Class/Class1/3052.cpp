#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	unordered_set<int> remainders;
	for (int i = 0; i < 10; ++i)
	{
		int number = 0;
		cin >> number;
		remainders.emplace(number % 42);
	}

	cout << remainders.size();
}