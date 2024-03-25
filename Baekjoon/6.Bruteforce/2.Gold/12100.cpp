#include <iostream>
#include <cstring>
using namespace std;

int N, MaxBlock;
int Board[20][20];

void Move(int Dir)
{
	switch (Dir)
	{
	case 0: // L
		for (int i = 0; i < N; ++i)
		{
			for (int j = 1; j < N; ++j)
			{
				if (Board[i][j] == 0 || Board[i][j - 1] != 0)
				{
					continue;
				}

				int k = j - 2;
				while (k >= 0 && Board[i][k] == 0) { --k; }
				Board[i][k + 1] = Board[i][j];
				Board[i][j] = 0;
			}
		}
		break;

	case 1: // T
		for (int j = 0; j < N; ++j)
		{
			for (int i = 1; i < N; ++i)
			{
				if (Board[i][j] == 0 || Board[i - 1][j] != 0)
				{
					continue;
				}

				int k = i - 2;
				while (k >= 0 && Board[k][j] == 0) { --k; }
				Board[k + 1][j] = Board[i][j];
				Board[i][j] = 0;
			}
		}
		break;

	case 2: // R
		for (int i = 0; i < N; ++i)
		{
			for (int j = N - 2; j >= 0; --j)
			{
				if (Board[i][j] == 0 || Board[i][j + 1] != 0)
				{
					continue;
				}

				int k = j + 2;
				while (k <= N - 1 && Board[i][k] == 0) { ++k; }
				Board[i][k - 1] = Board[i][j];
				Board[i][j] = 0;
			}
		}
		break;

	case 3: // B
		for (int j = 0; j < N; ++j)
		{
			for (int i = N - 2; i >= 0; --i)
			{
				if (Board[i][j] == 0 || Board[i + 1][j] != 0)
				{
					continue;
				}

				int k = i + 2;
				while (k <= N - 1 && Board[k][j] == 0) { ++k; }
				Board[k - 1][j] = Board[i][j];
				Board[i][j] = 0;
			}
		}
		break;
	}
}

void Combine(int Dir)
{
	bool Combined[20][20] = {};

	switch (Dir)
	{
	case 0: // L
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N - 1; ++j)
			{
				if (Combined[i][j] || Combined[i][j + 1])
				{
					continue;
				}

				if (Board[i][j] == Board[i][j + 1])
				{
					Board[i][j] = 2 * Board[i][j];
					Board[i][j + 1] = 0;
					Combined[i][j] = true;
					Combined[i][j + 1] = true;
				}
			}
		}
		break;

	case 1: // T
		for (int j = 0; j < N; ++j)
		{
			for (int i = 0; i < N - 1; ++i)
			{
				if (Combined[i][j] || Combined[i + 1][j])
				{
					continue;
				}

				if (Board[i][j] == Board[i + 1][j])
				{
					Board[i][j] = 2 * Board[i][j];
					Board[i + 1][j] = 0;
					Combined[i][j] = true;
					Combined[i + 1][j] = true;
				}
			}
		}
		break;

	case 2: // R
		for (int i = 0; i < N; ++i)
		{
			for (int j = N - 1; j > 0; --j)
			{
				if (Combined[i][j] || Combined[i][j - 1])
				{
					continue;
				}

				if (Board[i][j] == Board[i][j - 1])
				{
					Board[i][j] = 2 * Board[i][j];
					Board[i][j - 1] = 0;
					Combined[i][j] = true;
					Combined[i][j - 1] = true;
				}
			}
		}
		break;

	case 3: // B
		for (int j = 0; j < N; ++j)
		{
			for (int i = N - 1; i > 0; --i)
			{
				if (Combined[i][j] || Combined[i - 1][j])
				{
					continue;
				}

				if (Board[i][j] == Board[i - 1][j])
				{
					Board[i][j] = 2 * Board[i][j];
					Board[i - 1][j] = 0;
					Combined[i][j] = true;
					Combined[i - 1][j] = true;
				}
			}
		}
		break;
	}
}

void Action(int Dir)
{
	Move(Dir);
	Combine(Dir);
	Move(Dir);
}

bool SameResult(int Stored[][20])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Board[i][j] != Stored[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

void MaxCheck()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			MaxBlock = max(MaxBlock, Board[i][j]);
		}
	}
}

void Backtracking(int Idx)
{
	if (Idx == 5)
	{
		MaxCheck();
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int Stored[20][20] = {};
		memcpy(Stored, Board, sizeof(Stored));
		Action(i);
		if (SameResult(Stored))
		{
			MaxCheck();
			continue;
		}

		Backtracking(Idx + 1);
		memcpy(Board, Stored, sizeof(Board));
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
			cin >> Board[i][j];
		}
	}

	Backtracking(0);
	cout << MaxBlock;
}