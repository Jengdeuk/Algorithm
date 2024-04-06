#include <iostream>
#include <list>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int N, M, K, T, P;
list<int> Mosquito[50][50];
p MP[10];

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };
bool Visited[50][50];

int Max, MKill;
bool bFound;

void DFS(int Time, int Kill, int R, int C)
{
	Visited[R][C] = true;
	Kill += Mosquito[R][C].size();
	MKill = max(MKill, Kill);
	if (Time == T)
	{
		return;
	}

	if (MKill == K)
	{
		bFound = true;
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int NR = R + DY[i];
		int NC = C + DX[i];
		if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1
			|| Visited[NR][NC])
		{
			continue;
		}

		if (bFound)
		{
			return;
		}

		DFS(Time + 1, Kill, NR, NC);
		Visited[NR][NC] = false;
	}
}

int Woojung()
{
	Max = 0;

	for (int i = 0; i < K; ++i)
	{
		memset(Visited, false, sizeof(Visited));
		MKill = 0;
		bFound = false;
		DFS(0, 0, MP[i].first, MP[i].second);
		Max = max(Max, MKill);
	}

	return Max;
}

void BFS(int SR, int SC)
{
	queue<pair<int, pair<int, int>>> SQ;

	Visited[SR][SC] = true;
	SQ.emplace(0, pair<int, int>(SR, SC));
	while (!SQ.empty())
	{
		int L = SQ.front().first;
		int R = SQ.front().second.first;
		int C = SQ.front().second.second;
		SQ.pop();

		if (L > 0)
		{
			for (const int& M : Mosquito[R][C])
			{
				if (P / L >= M)
				{
					++MKill;
				}
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1
				|| Visited[NR][NC])
			{
				continue;
			}

			Visited[NR][NC] = true;
			SQ.emplace(L + 1, pair<int, int>(NR, NC));
		}
	}
}

int Arrm()
{
	Max = 0;

	for (int i = 0; i < K; ++i)
	{
		memset(Visited, false, sizeof(Visited));
		MKill = Mosquito[MP[i].first][MP[i].second].size();

		BFS(MP[i].first, MP[i].second);
		Max = max(Max, MKill);
	}

	return Max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K >> T >> P;

	for (int i = 0; i < K; ++i)
	{
		int R, C, S;
		cin >> R >> C >> S;
		Mosquito[R][C].emplace_back(S);
		MP[i] = p(R, C);
	}

	cout << Woojung() << ' ' << Arrm();
}