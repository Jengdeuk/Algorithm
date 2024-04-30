#include <iostream>
#include <string>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;

const int Inf = INT_MAX;
const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
bool IsWall[100][100];
int Cost[100][100];

void Dijkstra()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			Cost[i][j] = Inf;
		}
	}

	priority_queue<pp, vector<pp>, greater<pp>> PQ;
	Cost[0][0] = 0;
	PQ.emplace(0, p(0, 0));
	while (!PQ.empty())
	{
		int Cst = PQ.top().first;
		int R = PQ.top().second.first;
		int C = PQ.top().second.second;
		PQ.pop();
		if (Cst > Cost[R][C])
		{
			continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1)
			{
				continue;
			}

			int NCst = Cst + ((IsWall[NR][NC]) ? 1 : 0);
			if (NCst < Cost[NR][NC])
			{
				Cost[NR][NC] = NCst;
				PQ.emplace(NCst, p(NR, NC));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> M >> N;
	for (int i = 0; i < N; ++i)
	{
		string Line;
		cin >> Line;
		for (int j = 0; j < M; ++j)
		{
			IsWall[i][j] = Line[j] - '0';
		}
	}

	Dijkstra();
	cout << Cost[N - 1][M - 1];
}