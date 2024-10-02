#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, p> pp;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
char Map[50][50];
bool V[1 << 6][50][50];

bool IsValid(int Bit, int R, int C)
{
	if (R < 0 || R >= N || C < 0 || C >= M || V[Bit][R][C] || Map[R][C] == '#')
	{
		return false;
	}

	if (Map[R][C] >= 'A' && Map[R][C] <= 'F')
	{
		return (Bit & (1 << Map[R][C] - 'A'));
	}

	return true;
}

int BFS(int SR, int SC)
{
	queue<pp> Q;
	V[0][SR][SC] = true;
	Q.emplace(p(0, 0), p(SR, SC));
	while (!Q.empty())
	{
		int Step = Q.front().first.first;
		int KeyBit = Q.front().first.second;
		int R = Q.front().second.first;
		int C = Q.front().second.second;
		Q.pop();

		if (Map[R][C] == '1')
		{
			return Step;
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(KeyBit, NR, NC))
			{
				int NewBit = KeyBit;
				if (Map[NR][NC] >= 'a' && Map[NR][NC] <= 'f')
				{
					NewBit |= (1 << (Map[NR][NC] - 'a'));
				}
				V[NewBit][NR][NC] = true;
				Q.emplace(p(Step + 1, NewBit), p(NR, NC));
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

	int SR, SC;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < M; ++j)
		{
			Map[i][j] = S[j];
			if (S[j] == '0')
			{
				Map[i][j] = '.';
				SR = i;
				SC = j;
			}
		}
	}

	cout << BFS(SR, SC);
}