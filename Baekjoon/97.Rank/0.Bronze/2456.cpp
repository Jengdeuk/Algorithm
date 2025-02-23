#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, tuple<int, int, int>> pt;

pt s[3];

bool compare(const pt& l, const pt& r)
{
	return (l.first.second == r.first.second ? l.second > r.second : l.first.second > r.first.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 3; ++i)
		s[i].first.first = i + 1;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int score;
			cin >> score;
			s[j].first.second += score;
			switch (score)
			{
			case 3:
				++get<0>(s[j].second);
				break;
			case 2:
				++get<1>(s[j].second);
				break;
			case 1:
				++get<2>(s[j].second);
				break;
			}
		}
	}

	sort(s, s + 3, compare);

	bool isAllSame = false;
	if (s[0].first.second == s[1].first.second && get<0>(s[0].second) == get<0>(s[1].second) && get<1>(s[0].second) == get<1>(s[1].second))
		isAllSame = true;

	if (isAllSame == false)
		cout << s[0].first.first << ' ' << s[0].first.second;
	else
		cout << 0 << ' ' << s[0].first.second;
}