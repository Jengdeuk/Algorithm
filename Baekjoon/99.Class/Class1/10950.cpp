#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;

	vector<int> result;
	result.reserve(t);
	for (int i = 0; i < t; ++i)
	{
		int a, b = 0;
		cin >> a >> b;
		result.emplace_back(a + b);
	}

	for (const int& number : result)
	{
		cout << number << "\n";
	}
}