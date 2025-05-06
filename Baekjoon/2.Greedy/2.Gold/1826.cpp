#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int n;
p s[10000];

bool compare(const p& l, const p& r)
{
	return l.second == r.second ? l.first > r.first : l.second < r.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i].second >> s[i].first;

	sort(s, s + n, compare);

	int g, o;
	cin >> g >> o;

	priority_queue<p> q;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (o >= g)
			break;

		while (q.empty() == false && o < g && o < s[i].second)
		{
			o += q.top().first;
			q.pop();
			cnt++;
		}

		if (o < s[i].second)
			break;

		q.emplace(s[i]);
	}

	while (q.empty() == false && o < g)
	{
		o += q.top().first;
		q.pop();
		cnt++;
	}

	if (o >= g)
		cout << cnt;
	else
		cout << -1;
}