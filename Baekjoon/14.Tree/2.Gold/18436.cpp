#include <iostream>
using namespace std;

typedef pair<int, int> p;

int n, si;
p t[1 << 18];

void replace(int idx, int value)
{
	idx += si;
	if (value % 2 == 0)
		t[idx] = p(1, 0);
	else
		t[idx] = p(0, 1);

	int p;
	while ((p = idx >> 1) > 0)
	{
		if (idx % 2 == 0)
		{
			t[p].first = t[idx].first + t[idx + 1].first;
			t[p].second = t[idx].second + t[idx + 1].second;
		}
		else
		{
			t[p].first = t[idx - 1].first + t[idx].first;
			t[p].second = t[idx - 1].second + t[idx].second;
		}

		idx = p;
	}
}

void print(bool isEven, int l, int r)
{
	l += si;
	r += si;

	p sum(0, 0);
	while (l <= r)
	{
		if (l % 2 == 1)
		{
			sum.first += t[l].first;
			sum.second += t[l].second;
		}

		if (r % 2 == 0)
		{
			sum.first += t[r].first;
			sum.second += t[r].second;
		}

		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}

	if (isEven)
		cout << sum.first;
	else
		cout << sum.second;
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	si = 1;
	while (si < n)
		si = (si << 1);

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (num % 2 == 0)
			t[si + i].first++;
		else
			t[si + i].second++;
	}

	for (int i = si - 1; i > 0; --i)
	{
		t[i].first = t[i << 1].first + t[(i << 1) + 1].first;
		t[i].second = t[i << 1].second + t[(i << 1) + 1].second;
	}

	int m;
	cin >> m;
	while (m--)
	{
		int q;
		cin >> q;
		switch (q)
		{
		case 1:
		{
			int i, x;
			cin >> i >> x;
			replace(i - 1, x);
		}
			break;
		case 2:
		case 3:
		{
			int l, r;
			cin >> l >> r;
			print(q == 2, l - 1, r - 1);
		}
			break;
		}
	}
}