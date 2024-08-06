#include <iostream>
#include <climits>
using namespace std;

typedef long long ll;

int N;
ll S[501], Sum[501];
ll DP[501][501];

void Test()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> S[i];
		Sum[i] = Sum[i - 1] + S[i];
	}

	for (int l = 1; l < N; ++l)
	{
		for (int i = 1; i < N; ++i)
		{
			int j = i + l;
			if (j > N)
			{
				break;
			}

			ll Min = LLONG_MAX;
			for (int k = i; k < j; ++k)
			{
				Min = min(Min, DP[i][k] + DP[k + 1][j] + (Sum[j] - Sum[i - 1]));
			}

			DP[i][j] = Min;
		}
	}

	cout << DP[1][N] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}