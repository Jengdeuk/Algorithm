#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int M, N, K;
bool Visited[100][100];

int AreaNum;
int Area[10000];

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int BFS(int SR, int SC)
{
	queue<pair<int, int>> SQ;

	int Cnt = 1;
	Visited[SR][SC] = true;
	SQ.emplace(SR, SC);
	while (!SQ.empty())
	{
		int R = SQ.front().first;
		int C = SQ.front().second;
		SQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > M - 1 || NC < 0 || NC > N - 1
				|| Visited[NR][NC])
			{
				continue;
			}

			++Cnt;
			Visited[NR][NC] = true;
			SQ.emplace(NR, NC);
		}
	}

	return Cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> M >> N >> K;
	for (int i = 0; i < K; ++i)
	{
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;

		for (int j = Y1; j < Y2; ++j)
		{
			for (int k = X1; k < X2; ++k)
			{
				Visited[j][k] = true;
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!Visited[i][j])
			{
				Area[AreaNum] = BFS(i, j);
				++AreaNum;
			}
		}
	}

	sort(Area, Area + AreaNum);

	cout << AreaNum << '\n';
	for (int i = 0; i < AreaNum; ++i)
	{
		cout << Area[i] << ' ';
	}
}