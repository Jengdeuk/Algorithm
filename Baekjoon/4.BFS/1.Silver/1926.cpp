#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
int Map[500][500];
bool Vst[500][500];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && Map[R][C] == 1 && !Vst[R][C]);
}

int BFS(int SR, int SC)
{
	int Cnt = 1;

	queue<p> Q;
	Vst[SR][SC] = true;
	Q.emplace(SR, SC);
	while (!Q.empty())
	{
		int R = Q.front().first;
		int C = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NR, NC))
			{
				++Cnt;
				Vst[NR][NC] = true;
				Q.emplace(NR, NC);
			}
		}
	}

	return Cnt;
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

	int Cnt = 0, Max = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] && !Vst[i][j])
			{
				++Cnt;
				Max = max(Max, BFS(i, j));
			}
		}
	}

	cout << Cnt << '\n' << Max;
}