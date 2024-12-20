#include <iostream>
using namespace std;

int N, Cnt[101];
int M[1002][1002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int n = 1; n <= N; ++n)
	{
		int C, R, X, Y;
		cin >> C >> R >> X >> Y;

		for (int i = R; i < R + Y; ++i)
		{
			for (int j = C; j < C + X; ++j)
			{
				M[i][j] = n;
			}
		}
	}

	for (int i = 0; i < 1002; ++i)
	{
		for (int j = 0; j < 1002; ++j)
		{
			if (M[i][j] > 0)
			{
				++Cnt[M[i][j]];
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << Cnt[i] << '\n';
	}
}