#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char Board[50][50];

char BW[8][8] =
{
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
};

char WB[8][8] =
{
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
	{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
	{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
};

vector<int> Solution;

int CompareBW(int Row, int Col)
{
	int Count = 0;

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (Board[Row + i][Col + j] != BW[i][j])
			{
				++Count;
			}
		}
	}

	return Count;
}

int CompareWB(int Row, int Col)
{
	int Count = 0;

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (Board[Row + i][Col + j] != WB[i][j])
			{
				++Count;
			}
		}
	}

	return Count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char Color;
			cin >> Color;
			Board[i][j] = Color;
		}
	}

	Solution.reserve((N - 7) * (M - 7) * 2);
	for (int i = 0; i < N - 7; ++i)
	{
		for (int j = 0; j < M - 7; ++j)
		{
			Solution.emplace_back(CompareBW(i, j));
			Solution.emplace_back(CompareWB(i, j));
		}
	}

	cout << *min_element(Solution.begin(), Solution.end());
}