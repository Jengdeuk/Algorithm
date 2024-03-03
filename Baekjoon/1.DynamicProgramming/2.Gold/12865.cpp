#include <iostream>
using namespace std;

int DP[101][100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		int Weight, Value;
		cin >> Weight >> Value;

		for (int w = 0; w <= K; ++w)
		{
			if (Weight <= w)
			{
				DP[i][w] = max(DP[i - 1][w], DP[i - 1][w - Weight] + Value);
			}
			else
			{
				DP[i][w] = DP[i - 1][w];
			}
		}
	}

	cout << DP[N][K];
}