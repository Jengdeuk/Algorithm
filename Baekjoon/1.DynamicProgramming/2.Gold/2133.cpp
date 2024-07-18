#include <iostream>
#include <cmath>
using namespace std;

int DP[31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	if (N % 2 == 1)
	{
		cout << 0;
		return 0;
	}

	DP[2] = 3;
	DP[4] = 11;
	for (int i = 6; i <= N; i += 2)
	{
		DP[i] = DP[i - 2] * DP[2] + 2;
		int j = 4;
		while (i - j > 0)
		{
			DP[i] += DP[i - j] * 2;
			j += 2;
		}
	}

	cout << DP[N];
}