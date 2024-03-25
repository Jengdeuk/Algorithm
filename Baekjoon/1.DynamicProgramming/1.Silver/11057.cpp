#include <iostream>
using namespace std;

int DP[1001][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < 10; ++i)
	{
		DP[1][i] = 1;
	}

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k <= j; ++k)
			{
				DP[i][j] += DP[i - 1][k];
				DP[i][j] %= 10007;
			}
		}
	}

	int Sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		Sum += DP[N][i];
	} 
	cout << Sum % 10007;
}