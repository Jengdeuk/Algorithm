#include <iostream>
using namespace std;

long long DP[91][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	DP[1][0] = 0;
	DP[1][1] = 1;

	DP[2][0] = 1;
	DP[2][1] = 0;

	DP[3][0] = 1;
	DP[3][1] = 1;

	int N;
	cin >> N;
	for (int i = 4; i <= N; ++i)
	{
		DP[i][0] = DP[i - 1][1] + DP[i - 1][0];
		DP[i][1] = DP[i - 1][0];
	}

	cout << DP[N][0] + DP[N][1];
}