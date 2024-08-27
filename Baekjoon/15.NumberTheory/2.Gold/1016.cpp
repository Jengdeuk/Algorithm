#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long ll;

ll A, B;
unordered_map<ll, bool> Map;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> A >> B;
	for (ll i = 2; i <= 1000005; ++i)
	{
		ll SN = i * i;
		for (ll j = A / SN; j * SN <= B; ++j)
		{
			Map[j * SN] = true;
		}
	}

	ll Cnt = 0;
	for (ll i = A; i <= B; ++i)
	{
		if (!Map.count(i))
		{
			++Cnt;
		}
	}

	cout << Cnt;
}