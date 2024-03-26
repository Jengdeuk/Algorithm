#include <iostream>
using namespace std;

int DP[31][31];

void Test()
{
	int N, M;
	cin >> N >> M;
	cout << DP[M][N] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 1; i <= 30; ++i)
	{
		DP[i][0] = 1;
	}

	DP[1][1] = 1;
	DP[2][1] = 2;
	DP[2][2] = 1;

	for (int i = 3; i <= 30; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
		}
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}