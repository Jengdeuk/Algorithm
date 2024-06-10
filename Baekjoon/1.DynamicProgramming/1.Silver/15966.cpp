#include <iostream>
using namespace std;

int N;
int S[100000];
int DP[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Max = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];

		if (i == 0)
		{
			DP[S[i]] = 1;
		}
		else
		{
			DP[S[i]] = max(DP[S[i]], DP[S[i] - 1] + 1);
		}

		Max = max(Max, DP[S[i]]);
	}

	cout << Max;
}