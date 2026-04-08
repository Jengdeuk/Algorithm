#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

const ll MaxNum = 1000000000LL * 1000000000LL;

int N, M;
ll T[100000];

bool IsValid(ll Time)
{
	ll Sum = 0;
	for (int i = 0; i < N; ++i)
	{
		Sum += Time / T[i];
		if (Sum >= M)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> T[i];
	}

	sort(T, T + N);

	ll Answer = MaxNum;

	ll L = 1;
	ll R = MaxNum;
	while (L <= R)
	{
		ll M = (L + R) >> 1;
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