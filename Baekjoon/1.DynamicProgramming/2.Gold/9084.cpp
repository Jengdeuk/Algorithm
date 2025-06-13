#include <iostream>
using namespace std;

int N, C[20], DP[10001];

void Test()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> C[i];
	}

	int M;
	cin >> M;
	for (int m = 0; m <= M; ++m)
	{
		DP[m] = 0;
	}

	DP[0] = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int m = C[i]; m <= M; ++m)
		{
			DP[m] += DP[m - C[i]];
		}
	}

	cout << DP[M] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) Test();
}