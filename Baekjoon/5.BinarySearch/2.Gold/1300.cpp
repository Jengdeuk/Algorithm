#include <iostream>
using namespace std;

typedef long long ll;

ll N, K;

ll Count(ll Num)
{
	ll Sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		Sum += min(Num / i, N);
	}

	return Sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;

	ll L = 1, R = N * N;
	while (L <= R)
	{
		ll M = (L + R) / 2;
		ll Cnt = Count(M);
		if (Cnt >= K)
		{
			R = M - 1;
		}
		else
		{
			L = M + 1;
		}
	}

	cout << L;
}