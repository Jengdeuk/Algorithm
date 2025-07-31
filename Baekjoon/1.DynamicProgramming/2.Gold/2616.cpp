#include <iostream>
using namespace std;

int N, M, PS[50001], DP[4][50001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int P;
		cin >> P;
		PS[i] = PS[i - 1] + P;
	}
	cin >> M;

	for (int i = 1; i <= 3; ++i)
	{
		for (int j = i * M; j <= N; ++j)
		{
			DP[i][j] = max(DP[i][j - 1], DP[i - 1][j - M] + (PS[j] - PS[j - M]));
		}
	}

	cout << DP[3][N];
}