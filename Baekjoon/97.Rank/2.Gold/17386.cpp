#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

ll ccw(const p& a, const p& b, const p& c)
{
	ll s = a.first * b.second + b.first * c.second + c.first * a.second
		- (b.first * a.second + c.first * b.second + a.first * c.second);

	if (s > 0)
		return 1;
	else if (s < 0)
		return -1;
	
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	p l1a, l1b;
	cin >> l1a.first >> l1a.second >> l1b.first >> l1b.second;

	p l2a, l2b;
	cin >> l2a.first >> l2a.second >> l2b.first >> l2b.second;

	cout << (ccw(l1a, l1b, l2a) * ccw(l1a, l1b, l2b) < 0 && ccw(l2a, l2b, l1a) * ccw(l2a, l2b, l1b) < 0);
}