#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, p> pp;
typedef pair<pp, bool> ppb;

const int DX[5] = { -1, 0, 1, 0, 0 };
const int DY[5] = { 0, -1, 0, 1, 0 };

int N, M, K;
int Map[1000][1000];
bool Visited[1000][1000][11][2];

int BFS(int SRow, int SCol)
{
	queue<ppb> SQ;
	SQ.emplace(pp(p(SRow, SCol), p(0, 1)), true);
	Visited[SRow][SCol][0][true] = true;

	while (!SQ.empty())
	{
		int R = SQ.front().first.first.first;
		int C = SQ.front().first.first.second;
		int B = SQ.front().first.second.first;
		int D = SQ.front().first.second.second;
		bool Day = SQ.front().second;
		SQ.pop();

		if (R == N - 1 && C == M - 1)
		{
			return D;
		}

		for (int i = 0; i < 5; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > N - 1
				|| NC < 0 || NC > M - 1)
			{
				continue;
			}

			if (Day && Map[NR][NC] == 1 && B < K
				&& !Visited[NR][NC][B - 1][Day]
				&& !Visited[NR][NC][B - 1][!Day])
			{
				Visited[NR][NC][B + 1][!Day] = true;
				SQ.emplace(pp(p(NR, NC), p(B + 1, D + 1)), !Day);
			}
			else if ((Map[NR][NC] == 0 || i == 4)
				&& !Visited[NR][NC][B][!Day])
			{
				Visited[NR][NC][B][!Day] = true;
				SQ.emplace(pp(p(NR, NC), p(B, D + 1)), !Day);
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