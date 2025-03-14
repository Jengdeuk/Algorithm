#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

typedef pair<string, int> p;

unordered_map<string, int> um;

bool compare(const p& l, const p& r)
{
	return (l.second == r.second ? (l.first.size() == r.first.size() ? l.first < r.first : l.first.size() > r.first.size()) : l.second > r.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	while (n--)
	{
		string s;
		cin >> s;
		if (s.size() < m)
			continue;

		um[s]++;
	}

	vector<p> v(um.begin(), um.end());

	sort(v.begin(), v.end(), compare);

	for (const p& e : v)
		cout << e.first << '\n';
}