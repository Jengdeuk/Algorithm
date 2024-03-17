#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
bool Cheeze[100][100];

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

queue<pair<int, int>> SQ;
bool Visited[100][100];
int Air[100][100];

void BFS()
{
	memset(Visited, false, sizeof(Visited));
	memset(Air, 0, sizeof(Air));

	Visited[0][0] = true;
	SQ.emplace(0, 0);
	while (!SQ.empty())
	{
		int R = SQ.front().first;
		int C = SQ.front().second;
		SQ.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];

			if (NR < 0 || NR > N - 1
				|| NC < 0 || NC > M - 1
				|| (!Cheeze[NR][NC] && Visited[NR][NC]))
			{
				continue;
			}

			if (Cheeze[NR][NC])
			{
				++Air[NR][NC];
			}
			else
			{
				Visited[NR][NC] = true;
				SQ.emplace(NR, NC);
			}
		}
	}
}

void DeleteCheeze()
{
	BFS();

	for (int i = 1; i < N - 1; ++i)
	{
		for (int j = 1; j < M - 1; ++j)
		{
			if (Air[i][j] >= 2)
			{
				Cheeze[i][j] = false;
			}
		}
	}
}

bool HaveCheeze()
{
	for (int i = 1; i < N - 1; ++i)
	{
		for (int j = 1; j < M - 1; ++j)
		{
			if (Cheeze[i][j])
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
		for (int j = 0; j < M; ++j)
		{
			cin >> Cheeze[i][j];
		}
	}

	int Time = 0;
	while (HaveCheeze())
	{
		DeleteCheeze();
		++Time;
	}

	cout << Time;
}