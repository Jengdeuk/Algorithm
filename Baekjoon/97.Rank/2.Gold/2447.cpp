#include <iostream>
using namespace std;

char Map[6561][6561];

void Rec(int R, int C, int N)
{
	if (N == 3)
	{
		for (int i = R; i < R + N; ++i)
		{
			for (int j = C; j < C + N; ++j)
			{
				Map[i][j] = '*';
			}
		}

		Map[R + 1][C + 1] = ' ';
		return;
	}

	int NN = N / 3;

	Rec(R, C, NN);
	Rec(R + NN, C, NN);
	Rec(R + 2 * NN, C, NN);

	Rec(R, C + NN, NN);
	Rec(R + 2 * NN, C + NN, NN);

	Rec(R, C + 2 * NN, NN);
	Rec(R + NN, C + 2 * NN, NN);
	Rec(R + 2 * NN, C + 2 * NN, NN);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Map[i][j] = ' ';
		}
	}

	Rec(0, 0, N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << Map[i][j];
		}
		cout << '\n';
	}
}