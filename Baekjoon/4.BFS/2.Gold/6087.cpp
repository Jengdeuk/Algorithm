#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, p> pp;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
bool W[100][100];
int V[4][100][100];
p Start, End;

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && W[R][C] == false);
}

bool IsPutMirror(int PreDir, int NxtDir)
{
	switch (PreDir)
	{
	case 0:
	case 2:
		if (NxtDir == 1 || NxtDir == 3)
		{
			return true;
		}
		break;
	case 1:
	case 3:
		if (NxtDir == 0 || NxtDir == 2)
		{
			return true;
		}
		break;
	default:
		break;
	}

	return false;
}

int BFS()
{
	int Mirror = 123456789;

	queue<pp> Q;
	memset(V, -1, sizeof(V));
	Q.emplace(p(0, -1), Start);
	V[0][Start.first][Start.second] = -1;
	while (Q.empty() == false)
	{
		int CurMir = Q.front().first.first;
		int PreDir = Q.front().first.second;
		int R = Q.front().second.first;
		int C = Q.front().second.second;
		Q.pop();

		if (CurMir > Mirror)
		{
			continue;
		}

		if (R == End.first && C == End.second)
		{
			Mirror = min(Mirror, CurMir);
			continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			int NxtMir = CurMir + IsPutMirror(PreDir, i);
			if (IsValid(NR, NC) && (V[i][NR][NC] == -1 || NxtMir < V[i][NR][NC]) && NxtMir < Mirror)
			{
				V[i][NR][NC] = NxtMir;
				Q.emplace(p(NxtMir, i), p(NR, NC));
			}
		}
	}

	return Mirror;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> M >> N;

	bool bStart = true;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char Ch;
			cin >> Ch;
			switch (Ch)
			{
			case '*':
				W[i][j] = true;
				break;
			case 'C':
				if (bStart)
				{
					bStart = false;
					Start = p(i, j);
				}
				else
				{
					End = p(i, j);
				}
				break;
			}
		}
	}

	cout << BFS();
}