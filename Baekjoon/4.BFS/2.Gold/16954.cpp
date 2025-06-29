#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<bool, p> bp;

const int N = 8;

const int DX[9] = { -1, 0, 1, -1, 1, -1, 0, 1, 0 };
const int DY[9] = { -1, -1, -1, 0, 0, 1, 1, 1, 0 };

int W[N][N];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < N);
}

bool BFS()
{
	int SR = N - 1, SC = 0;

	queue<bp> Q;
	Q.emplace(true, p(SR, SC));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (W[i][j])
			{
				Q.emplace(false, p(i, j));
			}
		}
	}

	while (Q.empty() == false)
	{
		bool bPlayer = Q.front().first;
		int R = Q.front().second.first;
		int C = Q.front().second.second;
		Q.pop();

		if (bPlayer)
		{
			if (R == 0 && C == N - 1)
			{
				return true;
			}

			for (int i = 0; i < 9; ++i)
			{
				int NR = R + DY[i];
				int NC = C + DX[i];
				if (IsValid(NR, NC) && W[NR][NC] == false && (IsValid(NR - 1, NC) && W[NR - 1][NC]) == false)
				{
					Q.emplace(bPlayer, p(NR, NC));
				}
			}
		}
		else
		{
			int NR = R + DY[6];
			int NC = C + DX[6];
			if (IsValid(NR, NC))
			{
				W[NR][NC]++;
				Q.emplace(bPlayer, p(NR, NC));
			}
			W[R][C]--;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char Ch;
			cin >> Ch;
			W[i][j] += (Ch == '#');
		}
	}

	cout << BFS();
}