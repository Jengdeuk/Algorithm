#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<bool, p> bp;

const int md[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int front = 60;
const int back = 334;

int n;
bp fs[100000];

bool compare(bp l, bp r)
{
	return l.second.second == r.second.second ? l.second.first < r.second.first : l.second.second > r.second.second;
}

int date(int m, int d)
{
	int rv = 0;
	for (int i = 1; i < m; ++i)
	{
		rv += md[i - 1];
	}
	rv += d;

	return rv;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int m, d;

		cin >> m >> d;
		fs[i].second.first = date(m, d);

		cin >> m >> d;
		fs[i].second.second = date(m, d);
	}

	sort(fs, fs + n, compare);

	int cnt = 0;
	int curEnd = front;
	bool isFind = true;
	while (isFind && curEnd <= back)
	{
		isFind = false;
		for (int i = 0; i < n; ++i)
		{
			if (fs[i].first == false && fs[i].second.first <= curEnd)
			{
				isFind = true;
				fs[i].first = true;
				cnt++;
				curEnd = fs[i].second.second;
				break;
			}
		}
	}

	if (curEnd > back)
		cout << cnt;
	else
		cout << 0;
}