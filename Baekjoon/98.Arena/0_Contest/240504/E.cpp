#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
int TG, TB, X, B;
char Map[1001][1001];
bool Visited[1001][1001];

void BFS()
{
	priority_queue<ip, vector<ip>, greater<ip>> SQ;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (Map[i][j] == '*')
			{
				SQ.emplace(0, p(i, j));
			}
		}
	}

	while (!SQ.empty())
	{
		int T = SQ.top().first;
		int R = SQ.top().second.first;
		int C = SQ.top().second.second;
		SQ.pop();

		if (Map[R][C] == '.')
		{
			Map[R][C] = '*';
		}
		else if (Map[R][C] == '#' && T <= TG)
		{
			Map[R][C] = '*';
		}

		if (T >= TG || Visited[R][C])
		{
			continue;
		}

		Visited[R][C] = true;
		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 1 || NR > N || NC < 1 || NC > M || Visited[NR][NC])
			{
				continue;
			}

			if (Map[NR][NC] == '.')
			{
				SQ.emplace(T + 1, p(NR, NC));
			}
			else if (Map[NR][NC] == '#')
			{
				SQ.emplace(T + TB + 1, p(NR, NC));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> TG >> TB >> X >> B;

	for (int i = 1; i <= N; ++i)
	{
		string S;
		cin >> S;
		
		for (int j = 1; j <= M; ++j)
		{
			Map[i][j] = S[j - 1];
		}
	}

	BFS();

	bool bSafe = false;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (Map[i][j] != '*')
			{
				bSafe = true;
				cout << i << ' ' << j << '\n';
			}
		}
	}

	if (!bSafe)
	{
		cout << -1;
	}
}