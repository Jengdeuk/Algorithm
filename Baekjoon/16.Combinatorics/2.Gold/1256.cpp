#include <iostream>
using namespace std;

const int Max = 1000000000;

int N, M, K;
int DP[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;

	for (int i = 1; i <= 100; ++i)
	{
		DP[i][0] = 1;
		DP[0][i] = 1;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
			if (DP[i][j] > Max)
			{
				DP[i][j] = Max;
			}
		}
	}

	if (DP[N][M] < K)
	{
		cout << -1;
		return 0;
	}

	string Answer;
	int AN = N, ZN = M;
	for (int i = 0; i < N + M; ++i)
	{
		int Cnt = DP[AN - 1][ZN];

		if (AN == 0)
		{
			Answer.push_back('z');
			--ZN;
		}
		else if (ZN == 0)
		{
			Answer.push_back('a');
			--AN;
		}
		else if (K <= Cnt)
		{
			Answer.push_back('a');
			--AN;
		}
		else
		{
			K -= Cnt;
			Answer.push_back('z');
			--ZN;
		}
	}

	cout << Answer;
}