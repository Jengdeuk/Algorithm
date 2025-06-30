#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;
typedef pair<p, ip> pip;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M, Map[50][50];
bool V[3][5][50][50];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && Map[R][C] != -1);
}

int BFS(int SR, int SC)
{
	queue<pip> Q;
	V[0][4][SR][SC] = true;
	Q.emplace(p(0, -1), ip(0, p(SR, SC)));
	while (Q.empty() == false)
	{
		int T = Q.front().first.first;
		int PDir = Q.front().first.second;
		int Del = Q.front().second.first;
		int R = Q.front().second.second.first;
		int C = Q.front().second.second.second;
		Q.pop();

		if ((Del == 1 && Map[R][C] == 2) || (Del == 2 && Map[R][C] == 1))
		{
			return T;
		}

		Del = (Map[R][C] > 0 ? Map[R][C] : Del);

		for (int i = 0; i < 4; ++i)
		{
			if (i == PDir)
			{
				continue;
			}

			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NR, NC) && V[Del][i][NR][NC] == false)
			{
				V[Del][i][NR][NC] = true;
				Q.emplace(p(T + 1, i), ip(Del, p(NR, NC)));
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	int SR = 0, SC = 0, Cnt = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char Ch;
			cin >> Ch;
			switch (Ch)
			{
			case 'S':
				SR = i;
				SC = j;
				break;
			case 'C':
				Map[i][j] = Cnt++;
				break;
			case '#':
				Map[i][j] = -1;
				break;
			}
		}
	}

	cout << BFS(SR, SC);
}