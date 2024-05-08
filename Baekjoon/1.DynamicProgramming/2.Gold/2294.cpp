#include <iostream>
using namespace std;

const int Infinite = 987654321;

int N, K;
int Coin[100], DP[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> Coin[i];
	}

	for (int i = 1; i <= K; ++i)
	{
		DP[i] = Infinite;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = Coin[i]; j <= K; ++j)
		{
			DP[j] = min(DP[j], DP[j - Coin[i]] + 1);
		}
	}

	cout << (DP[K] != Infinite ? DP[K] : -1);
}