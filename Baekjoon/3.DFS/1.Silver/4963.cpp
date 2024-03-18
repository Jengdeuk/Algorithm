#include <iostream>
#include <cstring>
using namespace std;

const int DX[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int DY[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

int N, M;
bool Land[50][50];
bool Visited[50][50];

void DFS(int Row, int Col)
{
	Visited[Row][Col] = true;

	for (int i = 0; i < 8; ++i)
	{
		int NR = Row + DY[i];
		int NC = Col + DX[i];

		if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1
			|| Visited[NR][NC] || !Land[NR][NC])
		{
			continue;
		}

		DFS(NR, NC);
	}
}

void Test()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Land[i][j];
		}
	}

	memset(Visited, false, sizeof(Visited));

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Visited[i][j] || !Land[i][j])
			{
				continue;
			}

			DFS(i, j);
			++Cnt;
		}
	}

	cout << Cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		cin >> M >> N;
		if (N == 0 && M == 0)
		{
			break;
		}

		Test();
	}
}