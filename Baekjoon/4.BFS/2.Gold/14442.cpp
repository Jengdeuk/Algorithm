#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M, K;
int Map[1000][1000];
bool Visited[1000][1000][11];

int BFS(int SRow, int SCol)
{
	queue<pair<pair<int, int>, pair<int, int>>> SQ;
	SQ.emplace(pair<int, int>(SRow, SCol), pair<int, int>(0, 1));
	Visited[SRow][SCol][0] = true;

	while (!SQ.empty())
	{
		int R = SQ.front().first.first;
		int C = SQ.front().first.second;
		int B = SQ.front().second.first;
		int D = SQ.front().second.second;
		SQ.pop();

		if (R == N - 1 && C == M - 1)
		{
			return D;
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > N - 1
				|| NC < 0 || NC > M - 1)
			{
				continue;
			}

			if (Map[NR][NC] == 1 && B < K && !Visited[NR][NC][B - 1])
			{
				Visited[NR][NC][B + 1] = true;
				SQ.emplace(pair<int, int>(NR, NC), pair<int, int>(B + 1, D + 1));
			}
			else if (Map[NR][NC] == 0 && !Visited[NR][NC][B])
			{
				Visited[NR][NC][B] = true;
				SQ.emplace(pair<int, int>(NR, NC), pair<int, int>(B, D + 1));
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		string Str;
		cin >> Str;

		for (int j = 0; j < M; ++j)
		{
			int Num = Str[j] - '0';
			Map[i][j] = Num;
		}
	}

	cout << BFS(0, 0);
}