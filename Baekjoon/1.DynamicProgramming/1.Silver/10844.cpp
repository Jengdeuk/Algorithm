#include <iostream>
#include <string>
using namespace std;

int DP[101][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	DP[1][0] = 0;
	for (int i = 1; i <= 9; ++i)
	{
		DP[1][i] = 1;
	}

	DP[2][0] = 1;
	DP[2][1] = 1;
	DP[2][9] = 1;
	for (int i = 2; i <= 8; ++i)
	{
		DP[2][i] = 2;
	}

	for (int i = 3; i <= N; ++i)
	{
		DP[i][0] = DP[i - 1][1];
		DP[i][9] = DP[i - 1][8];
		for (int j = 1; j <= 8; ++j)
		{
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
		}
	}

	int Sum = 0;
	for (int i = 0; i <= 9; ++i)
	{
		Sum = (Sum + DP[N][i]) % 1000000000;
	}

	cout << Sum;
}