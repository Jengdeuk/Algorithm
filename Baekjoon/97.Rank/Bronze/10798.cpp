#include <iostream>
#include <string>
using namespace std;

char Board[5][15];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			Board[i][j] = ' ';
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); ++j)
		{
			Board[i][j] = str[j];
		}
	}

	for (int j = 0; j < 15; ++j)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (Board[i][j] == ' ')
			{
				continue;
			}

			cout << Board[i][j];
		}
	}
}