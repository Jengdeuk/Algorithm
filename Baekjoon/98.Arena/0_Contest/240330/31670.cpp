#include <iostream>
using namespace std;

typedef long long ll;

ll DP[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		ll Num;
		cin >> Num;
		if (i != 1)
		{
			DP[i] = min(DP[i - 2], DP[i - 1]) + Num;
		}
		else
		{
			DP[i] = Num;
		}
	}

	if (N == 1)
	{
		cout << DP[N];
		return 0;
	}

	cout << min(DP[N - 1], DP[N]);
}