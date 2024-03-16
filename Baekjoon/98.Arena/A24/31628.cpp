#include <iostream>
#include <string>
using namespace std;

string Map[10][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		string First = Map[i][0];
		for (int j = 1; j < 10; ++j)
		{
			if (First.compare(Map[i][j]) != 0)
			{
				break;
			}
			else if (j == 9)
			{
				cout << 1;
				return 0;
			}
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		string First = Map[0][i];
		for (int j = 1; j < 10; ++j)
		{
			if (First.compare(Map[j][i]) != 0)
			{
				break;
			}
			else if (j == 9)
			{
				cout << 1;
				return 0;
			}
		}
	}

	cout << 0;
}