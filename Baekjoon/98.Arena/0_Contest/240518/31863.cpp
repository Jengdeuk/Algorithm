#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
char Map[1000][1000];

void BFS(int SR, int SC)
{
	queue<p> SQ;
	SQ.emplace(SR, SC);

	while (!SQ.empty())
	{
		int R = SQ.front().first;
		int C = SQ.front().second;
		SQ.pop();

		if (Map[R][C] == '@')
		{
			for (int i = 0; i < 4; ++i)
			{
				for (int k = 1; k <= 2; ++k)
				{
					int NR = R + DY[i] * k;
					int NC = C + DX[i] * k;
					if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1
						|| Map[NR][NC] == '|')
					{
						break;
					}

					if (Map[NR][NC] == '*')
					{
						Map[NR][NC] = '-';
						SQ.emplace(NR, NC);
					}
					else if (Map[NR][NC] == '#')
					{
						Map[NR][NC] = '*';
					}
				}
			}
		}
		else if (Map[R][C] == '-')
		{
			for (int i = 0; i < 4; ++i)
			{
				int NR = R + DY[i];
				int NC = C + DX[i];
				if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1
					|| Map[NR][NC] == '|')
				{
					continue;
				}

				if (Map[NR][NC] == '*')
				{
					Map[NR][NC] = '-';
					SQ.emplace(NR, NC);
				}
				else if (Map[NR][NC] == '#')
				{
					Map[NR][NC] = '*';
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	int R, C;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < M; ++j)
		{
			Map[i][j] = S[j];
			if (S[j] == '@')
			{
				R = i;
				C = j;
			}
		}
	}

	BFS(R, C);

	int Cnt1 = 0, Cnt2 = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] == '-')
			{
				++Cnt1;
			}
			else if (Map[i][j] == '*' || Map[i][j] == '#')
			{
				++Cnt2;
			}
		}
	}

	cout << Cnt1 << ' ' << Cnt2;
}