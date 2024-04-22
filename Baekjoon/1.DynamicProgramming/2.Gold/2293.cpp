#include <iostream>
using namespace std;

int N, K;
int DP[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	DP[0] = 1;

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int Coin;
		cin >> Coin;

		for (int j = Coin; j <= K; ++j)
		{
			DP[j] += DP[j - Coin];
		}
	}

	cout << DP[K];
}