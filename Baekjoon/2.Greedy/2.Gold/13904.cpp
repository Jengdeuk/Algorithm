#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

bool compare(const p& l, const p& r)
{
	return l.second == r.second ? l.first <= r.first : l.second > r.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	p s[1000] = {};
	for (int i = 0; i < n; ++i)
		cin >> s[i].first >> s[i].second;

	sort(s, s + n, compare);

	bool v[1000] = {};
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = s[i].first - 1; j >= 0; --j)
		{
			if (v[j] == false)
			{
				v[j] = true;
				sum += s[i].second;
				break;
			}
		}
	}

	cout << sum;
}