#include <iostream>
#include <cstring>
using namespace std;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M, Time;
int Map[300][300];
bool V[300][300];

bool IsAllMelted()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] > 0)
			{
				return false;
			}
		}
	}

	return true;
}

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M);
}

void DFS(int R, int C)
{
	V[R][C] = true;

	for (int i = 0; i < 4; ++i)
	{
		int NR = R + DY[i];
		int NC = C + DX[i];
		if (IsValid(NR, NC) && Map[NR][NC] > 0 && !V[NR][NC])
		{
			DFS(NR, NC);
		}
	}
}

bool IsSeparated()
{
	int Cnt = 0;

	memset(V, false, sizeof(V));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] > 0 && !V[i][j])
			{
				DFS(i, j);
				++Cnt;
			}
		}
	}

	if (Cnt >= 2)
	{
		return true;
	}

	return false;
}

void Melt()
{
	int Temp[300][300] = {};

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] == 0)
			{
				continue;
			}

			int Cnt = 0;
			for (int k = 0; k < 4; ++k)
			{
				int NR = i + DY[k];
				int NC = j + DX[k];
				if (IsValid(NR, NC) && Map[NR][NC] == 0)
				{
					++Cnt;
				}
			}

			int NewHeight = Map[i][j] - Cnt;
			if (NewHeight > 0)
			{
				Temp[i][j] = NewHeight;
			}
		}
	}

	memcpy(Map, Temp, sizeof(Map));
}

bool Tick()
{
	if (IsAllMelted())
	{
		cout << 0;
		return false;
	}

	if (IsSeparated())
	{
		cout << Time;
		return false;
	}

	Melt();

	++Time;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Map[i][j];
		}
	}

	while (Tick()) {}
}