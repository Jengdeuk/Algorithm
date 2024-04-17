#include <iostream>
using namespace std;

int A[501];
int DP[501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, LastB;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Ai, Bi;
		cin >> Ai >> Bi;
		A[Ai] = Bi;
		LastB = max(LastB, Bi);
	}

	int Max = 0;
	for (int i = 1; i <= 500; ++i)
	{
		if (A[i] == 0)
		{
			continue;
		}

		for (int j = 1; j < i; ++j)
		{
			if (A[j] == 0)
			{
				continue;
			}

			if (A[j] < A[i] && DP[j] > DP[i])
			{
				DP[i] = DP[j];
			}
		}

		++DP[i];
		Max = max(Max, DP[i]);
	}

	cout << N - Max;
}