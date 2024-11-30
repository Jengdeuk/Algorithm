#include <iostream>
#include <string>
#include <queue>
#include <list>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
char Map[1000][1000];
bool V[1000][1000];
list<p> Fire;

bool IsFinished(int R, int C)
{
	return (R == 0 || R == N - 1 || C == 0 || C == M - 1);
}

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && Map[R][C] != '#' && Map[R][C] != 'F');
}

int BFS(int SR, int SC)
{
	queue<ip> Q;
	V[SR][SC] = true;
	Q.emplace(0, p(SR, SC));
	for (p f : Fire)
	{
		Q.emplace(-1, f);
	}

	while (!Q.empty())
	{
		int T = Q.front().first;
		int R = Q.front().second.first;
		int C = Q.front().second.second;
		Q.pop();

		if (T >= 0 && Map[R][C] == 'F')
		{
			continue;
		}

		if (T >= 0 && IsFinished(R, C))
		{
			return T + 1;
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NR, NC))
			{
				if (T >= 0 && !V[NR][NC])
				{
					V[NR][NC] = true;
					Q.emplace(T + 1, p(NR, NC));
				}
				else if (T == -1)
				{
					Map[NR][NC] = 'F';
					Q.emplace(T, p(NR, NC));
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int SR, SC;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;

		for (int j = 0; j < M; ++j)
		{
			Map[i][j] = S[j];
			if (S[j] == 'J')
			{
				SR = i;
				SC = j;
			}
			else if (S[j] == 'F')
			{
				Fire.emplace_back(i, j);
			}
		}
	}

	int Time = BFS(SR, SC);
	if (Time > -1)
	{
		cout << Time;
	}
	else
	{
		cout << "IMPOSSIBLE";
	}
}