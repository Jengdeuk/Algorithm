#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, gL, gR;
int Num[50][50];

int Cnt, Sum;
bool Visited[50][50];
queue<p> NQ;

void BFS(int SR, int SC)
{
	queue<p> SQ;
	Visited[SR][SC] = true;
	SQ.emplace(SR, SC);
	NQ.emplace(SR, SC);
	while (!SQ.empty())
	{
		int R = SQ.front().first;
		int C = SQ.front().second;
		SQ.pop();

		++Cnt;
		Sum += Num[R][C];
		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > N - 1 || NC < 0 || NC > N - 1
				|| Visited[NR][NC]
				|| abs(Num[R][C] - Num[NR][NC]) < gL
				|| abs(Num[R][C] - Num[NR][NC]) > gR)
			{
				continue;
			}

			Visited[NR][NC] = true;
			SQ.emplace(NR, NC);
			NQ.emplace(NR, NC);
		}
	}
}

bool Move()
{
	bool bMove = false;

	memset(Visited, false, sizeof(Visited));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Visited[i][j])
			{
				continue;
			}

			Cnt = 0;
			Sum = 0;

			BFS(i, j);
			if (Cnt == 1)
			{
				NQ.pop();
				continue;
			}

			while (!NQ.empty())
			{
				int R = NQ.front().first;
				int C = NQ.front().second;
				NQ.pop();

				Num[R][C] = Sum / Cnt;
				bMove = true;
			}
		}
	}

	return bMove;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> gL >> gR;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Num[i][j];
		}
	}

	int Day = 0;
	while (Move())
	{
		++Day;
	}

	cout << Day;
}