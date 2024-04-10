#include <iostream>
#include <list>
using namespace std;

typedef pair<int, int> p;

int N;
bool bEven;
bool CanPut[10][10];
list<int> Board[10];

int Max1, Max2;

bool Check(int R, int C)
{
	for (int r = 0; r < N; ++r)
	{
		if (r == R)
		{
			continue;
		}

		for (const int& c : Board[r])
		{
			if (abs(r - R) == abs(c - C))
			{
				return false;
			}
		}
	}

	return true;
}

void Backtracking(bool bBlack, int Cnt, int Idx)
{
	if (Idx >= N * N)
	{
		if (bBlack)
		{
			Max1 = max(Max1, Cnt);
		}
		else
		{
			Max2 = max(Max2, Cnt);
		}
		return;
	}

	int R = Idx / N;
	int C = Idx % N;
	int NextIdx;
	if (bEven)
	{
		if (bBlack)
		{
			if (R % 2 == 0)
			{
				NextIdx = (C + 2 > N - 1) ? Idx + 3 : Idx + 2;
			}
			else
			{
				NextIdx = (C + 1 > N - 1) ? Idx + 1 : Idx + 2;
			}
		}
		else
		{
			if (R % 2 == 0)
			{
				NextIdx = (C + 1 > N - 1) ? Idx + 1 : Idx + 2;
			}
			else
			{
				NextIdx = (C + 2 > N - 1) ? Idx + 3 : Idx + 2;
			}
		}
	}
	else
	{
		NextIdx = Idx + 2;
	}

	if (!CanPut[R][C])
	{
		Backtracking(bBlack, Cnt, NextIdx);
		return;
	}

	if (Check(R, C))
	{
		Board[R].emplace_back(C);
		Backtracking(bBlack, Cnt + 1, NextIdx);

		Board[R].pop_back();
		Backtracking(bBlack, Cnt, NextIdx);
	}
	else
	{
		Backtracking(bBlack, Cnt, NextIdx);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> CanPut[i][j];
		}
	}

	bEven = (N % 2 == 0);

	Backtracking(true, 0, 0);
	Backtracking(false, 0, 1);
	cout << Max1 + Max2;
}