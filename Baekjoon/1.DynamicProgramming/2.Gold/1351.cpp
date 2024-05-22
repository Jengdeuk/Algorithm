#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef long long ll;

ll N;
int P, Q;
unordered_map<ll, ll> DP;

ll Get(ll N)
{
	if (DP[N] != 0)
	{
		return DP[N];
	}

	return DP[N] = Get(N / P) + Get(N / Q);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> P >> Q;
	DP[0] = 1;
	cout << Get(N);
}