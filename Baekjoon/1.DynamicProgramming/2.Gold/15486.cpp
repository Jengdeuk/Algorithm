#include <iostream>
using namespace std;

int N;
int DP[1500002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	int Max = 0;
	for (int i = 1; i <= N; ++i)
	{
		int T, P;
		cin >> T >> P;

		DP[i] = max(DP[i], Max);
		if (T + i <= N + 1)
		{
			DP[T + i] = max(DP[T + i], DP[i] + P);
		}

		Max = max(Max, DP[i]);
	}

	cout << max(Max, DP[N + 1]);
}