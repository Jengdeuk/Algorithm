#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> pos;

const int DX[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
const int DY[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int N;
bool Visited[300][300];

int BFS(const pos& S, const pos& E)
{
	memset(Visited, false, sizeof(Visited));

	queue<pair<pos, int>> SQ;

	Visited[S.first][S.second] = true;
	SQ.emplace(S, 0);
	while (!SQ.empty())
	{
		int R = SQ.front().first.first;
		int C = SQ.front().first.second;
		int D = SQ.front().second;
		SQ.pop();

		if (R == E.first && C == E.second)
		{
			return D;
		}

		for (int i = 0; i < 8; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > N - 1 || NC < 0 || NC > N - 1
				|| Visited[NR][NC])
			{
				continue;
			}

			Visited[NR][NC] = true;
			SQ.emplace(pos(NR, NC), D + 1);
		}
	}
}

void Test()
{
	cin >> N;
	
	pos Start, End;
	cin >> Start.first >> Start.second;
	cin >> End.first >> End.second;

	cout << BFS(Start, End) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}