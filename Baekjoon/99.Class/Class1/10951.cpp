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
		eof = (cin >> a >> b).eof() ? true : false;
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