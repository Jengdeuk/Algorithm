#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, int> p;

int n;
unordered_map<ll, int> m;

bool compare(const p& l, const p& r)
{
	return (l.second == r.second ? l.first < r.first : l.second > r.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	while (n--)
	{
		ll num;
		cin >> num;
		m[num]++;
	}

	vector<p> v(m.begin(), m.end());
	sort(v.begin(), v.end(), compare);
	cout << v.front().first;
}