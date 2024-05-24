#include <iostream>
using namespace std;

const int Mod = 1000000000;

int N, K;
int DP[201][201];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	
	for (int i = 1; i <= N; ++i)
	{
		DP[i][1] = 1;
	}

	for (int j = 1; j <= K; ++j)
	{
		DP[1][j] = j;
	}

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 2; j <= K; ++j)
		{
			DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % Mod;
		}
	}

	cout << DP[N][K];
}