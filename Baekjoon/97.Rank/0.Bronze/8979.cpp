#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> t;
typedef pair<t, int> p;

int n, k;
p s[1000];
int r[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int num, gold, silver, bronze;
		cin >> num >> gold >> silver >> bronze;
		
		s[num - 1].first = { gold, silver, bronze };
		s[num - 1].second = num - 1;
	}

	sort(s, s + n, greater<>());

	int rank = 0;
	t prev = { 0, 0, 0 };
	for (int i = 0; i < n; ++i)
	{
		t medal = s[i].first;
		int num = s[i].second;

		if (get<0>(medal) != get<0>(prev) || get<1>(medal) != get<1>(prev) || get<2>(medal) != get<2>(prev))
		{
			rank = i + 1;
		}

		r[num] = rank;
		prev = medal;
	}

	cout << r[k - 1];
}