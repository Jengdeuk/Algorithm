#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
char F[250][250];
bool V[250][250];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && V[R][C] == false && F[R][C] != '#');
}

p BFS(int SR, int SC)
{
	int ON = 0, VN = 0;
	queue<p> Q;
	V[SR][SC] = true;
	Q.emplace(SR, SC);
	while (Q.empty() == false)
	{
		int R = Q.front().first;
		int C = Q.front().second;
		Q.pop();

		switch (F[R][C])
		{
		case 'o':
			ON++;
			break;
		case 'v':
			VN++;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NR, NC))
			{
				V[NR][NC] = true;
				Q.emplace(NR, NC);
			}
		}
	}

	if (ON > VN)
	{
		VN = 0;
	}
	else
	{
		ON = 0;
	}

	return p(ON, VN);
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
			F[i][j] = S[j];
		}
	}

	int ON = 0, VN = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (V[i][j] || F[i][j] == '#')
			{
				continue;
			}

			p Ret = BFS(i, j);
			ON += Ret.first;
			VN += Ret.second;
		}
	}

	cout << ON << ' ' << VN;
}