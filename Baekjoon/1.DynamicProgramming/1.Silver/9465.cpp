#include <iostream>
using namespace std;

int ST[2][100000];
int DP[2][100000];

void Test()
{
	int N;
	cin >> N;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> ST[i][j];
		}
	}

	if (N <= 1)
	{
		cout << max(ST[0][0], ST[1][0]) << '\n';
		return;
	}

	DP[0][0] = ST[0][0];
	DP[1][0] = ST[1][0];

	DP[0][1] = DP[1][0] + ST[0][1];
	DP[1][1] = DP[0][0] + ST[1][1];

	for (int j = 2; j < N; ++j)
	{
		DP[0][j] = max(DP[1][j - 2], DP[1][j - 1]) + ST[0][j];
		DP[1][j] = max(DP[0][j - 2], DP[0][j - 1]) + ST[1][j];
	}

	cout << max(DP[0][N - 1], DP[1][N - 1]) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}