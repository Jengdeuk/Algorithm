#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int N = 12;
const int M = 6;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

char F[N][M];
bool V[N][M];
queue<p> PopQ;

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M);
}

int BFS(int SR, int SC)
{
	int Cnt = 0;

	queue<p> Q;
	V[SR][SC] = true;
	Q.emplace(SR, SC);
	PopQ.emplace(SR, SC);
	while (Q.empty() == false)
	{
		int R = Q.front().first;
		int C = Q.front().second;
		Q.pop();

		Cnt++;

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NR, NC) && F[NR][NC] == F[R][C] && V[NR][NC] == false)
			{
				V[NR][NC] = true;
				Q.emplace(NR, NC);
				PopQ.emplace(NR, NC);
			}
		}
	}

	return Cnt;
}

bool PopPuyo()
{
	bool bPopped = false;

	memset(V, false, sizeof(V));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (F[i][j] == '.' || V[i][j])
			{
				continue;
			}

			if (BFS(i, j) >= 4)
			{
				bPopped = true;
				while (PopQ.empty() == false)
				{
					F[PopQ.front().first][PopQ.front().second] = '.';
					PopQ.pop();
				}
			}
			else
			{
				queue<p>().swap(PopQ);
			}
		}
	}

	return bPopped;
}

void MovePuyo()
{
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (F[i][j] != '.')
			{
				continue;
			}

			int UR = i - 1;
			while (UR >= 0 && F[UR][j] == '.')
			{
				UR -= 1;
			}

			if (UR >= 0)
			{
				F[i][j] = F[UR][j];
				F[UR][j] = '.';
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> F[i][j];
		}
	}

	int PopCount = 0;
	while (PopPuyo())
	{
		PopCount++;
		MovePuyo();
	}

	cout << PopCount;
}