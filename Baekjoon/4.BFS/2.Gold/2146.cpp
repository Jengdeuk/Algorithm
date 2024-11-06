#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, p> pp;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, K;
int M[100][100];
bool V[100][100];
int Min = 100000;

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < N && !V[R][C]);
}

void BFS(int SR, int SC)
{
	priority_queue<pp, vector<pp>, greater<pp>> Q;
	V[SR][SC] = true;
	Q.emplace(p(0, M[SR][SC]), p(SR, SC));
	while (!Q.empty())
	{
		int Step = Q.top().first.first;
		int SK = Q.top().first.second;
		int R = Q.top().second.first;
		int C = Q.top().second.second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (!IsValid(NR, NC))
			{
				continue;
			}

			V[NR][NC] = true;
			if (M[NR][NC] == SK)
			{
				Q.emplace(p(0, SK), p(NR, NC));
			}
			else if (M[NR][NC] > 0)
			{
				Min = min(Min, Step);
				Q.emplace(p(0, M[NR][NC]), p(NR, NC));
			}
			else
			{
				Q.emplace(p(Step + 1, SK), p(NR, NC));
			}
		}
	}
}

void DFS(int R, int C)
{
	for (int i = 0; i < 4; ++i)
	{
		int NR = R + DY[i];
		int NC = C + DX[i];
		if (IsValid(NR, NC) && M[NR][NC] == -1)
		{
			M[NR][NC] = K;
			DFS(NR, NC);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int Num;
			cin >> Num;
			if (Num > 0)
			{
				M[i][j] = -1;
			}
		}
	}

	int R = 0, C = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (M[i][j] == -1)
			{
				++K;
				M[i][j] = K;
				DFS(i, j);
				R = i, C = j;
			}
		}
	}

	BFS(R, C);

	cout << Min;
}