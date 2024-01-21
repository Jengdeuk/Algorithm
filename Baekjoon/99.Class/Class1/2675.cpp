#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int r;
		string stringCase;
		cin >> r >> stringCase;
		for (const char& character : stringCase)
		{
			for (int j = 0; j < r; ++j)
			{
				cout << character;
			}
		}
		cout << "\n";
	}
}