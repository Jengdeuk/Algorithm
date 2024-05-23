#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef long long ll;

ll N;
int P, Q, X, Y;
unordered_map<ll, ll> DP;

ll Get(ll N)
{
	if (N <= 0)
	{
		return 1;
	}

	if (DP[N] != 0)
	{
		return DP[N];
	}

	return DP[N] = Get(N / P - X) + Get(N / Q - Y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> P >> Q >> X >> Y;
	cout << Get(N);
}