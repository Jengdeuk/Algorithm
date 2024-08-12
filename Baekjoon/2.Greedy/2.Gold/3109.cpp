#include <iostream>
#include <string>
using namespace std;

const int DY[3] = { -1, 0, 1 };

int N, M;
char Map[10000][500];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && Map[R][C] == '.');
}

bool DFS(int R, int C)
{
	Map[R][C] = 'x';
	if (C == M - 1)
	{
		return true;
	}

	for (int i = 0; i < 3; ++i)
	{
		int NR = R + DY[i];
		int NC = C + 1;
		if (IsValid(NR, NC))
		{
			if (DFS(NR, NC))
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;

		for (int j = 0; j < M; ++j)
		{
			Map[i][j] = S[j];
		}
	}

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		if (DFS(i, 0))
		{
			++Cnt;
		}
	}

	cout << Cnt;
}