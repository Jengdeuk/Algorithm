#include <iostream>
#include <vector>
using namespace std;

int main()
{
	bool eof = false;
	vector<int> result;
	while (!eof)
	{
		int a, b = 0;
		cin >> a >> b;
		eof = (a == 0 && b == 0) ? true : false;
		if (!eof)
		{
			result.emplace_back(a + b);
		}
	}

	for (const int& number : result)
	{
		cout << number << "\n";
	}
}