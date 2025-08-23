#include <iostream>
using namespace std;

typedef long long ll;

int N, M, P[100000];

bool IsValid(ll K)
{
	int Cnt = 0;

	ll Money = 0;
	for (int i = 0; i < N; ++i)
	{
		if (K < P[i])
		{
			return false;
		}

		if (Money < P[i])
		{
			Money = K - P[i];
			if (++Cnt > M)
			{
				return false;
			}
		}
		else
		{
			Money -= P[i];
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> P[i];
	}

	ll L = 1, R = 10000000000;
	ll Answer = R;
	while (L <= R)
	{
		ll M = ((L + R) >> 1);
		if (IsValid(M))
		{
			Answer = M;
			R = M - 1;
		}
		else
		{
			L = M + 1;
		}
	}

	cout << Answer;
}