#include <iostream>
#include <string>
using namespace std;

char Tree[5005][5005];
bool Visited[5005][5005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 5005; ++i)
	{
		for (int j = 0; j < 5005; ++j)
		{
			Tree[i][j] = 'X';
		}
	}

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j <= i; ++j)
		{
			Tree[i][j] = str[j];
		}
	}

	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (Visited[i][j])
			{
				continue;
			}

			Visited[i][j] = true;
			if (Tree[i][j] == 'R')
			{
				if (Tree[i + 1][j] != 'R'
					|| Tree[i + 1][j + 1] != 'R')
				{
					cout << 0;
					return 0;
				}

				Visited[i + 1][j] = true;
				Visited[i + 1][j + 1] = true;
			}
			else
			{
				if (Tree[i][j + 1] != 'B'
					|| Tree[i + 1][j + 1] != 'B')
				{
					cout << 0;
					return 0;
				}

				Visited[i][j + 1] = true;
				Visited[i + 1][j + 1] = true;
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if (!Visited[N - 1][i])
		{
			cout << 0;
			return 0;
		}
	}

	cout << 1;
}