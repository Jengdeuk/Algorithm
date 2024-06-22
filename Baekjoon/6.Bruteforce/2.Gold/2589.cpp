#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, int> pp;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M, Max;
char Map[50][50];

void BFS(int SR, int SC)
{
	bool Vst[50][50] = {};
	Vst[SR][SC] = true;

	queue<pp> SQ;
	SQ.emplace(p(SR, SC), 0);
	while (!SQ.empty())
	{
		int R = SQ.front().first.first;
		int C = SQ.front().first.second;
		int D = SQ.front().second;
		SQ.pop();

		Max = max(Max, D);
		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1
				|| Map[NR][NC] == 'W' || Vst[NR][NC])
			{
				continue;
			}

			Vst[NR][NC] = true;
			SQ.emplace(p(NR, NC), D + 1);
		}
	}
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

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] == 'L')
			{
				BFS(i, j);
			}
		}
	}

	cout << Max;
}