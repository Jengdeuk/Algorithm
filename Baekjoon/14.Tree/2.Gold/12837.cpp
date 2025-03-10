#include <iostream>
using namespace std;

typedef long long ll;

int n, si;
ll t[1 << 21];

void replace(int idx, int value)
{
	idx = si + idx;
	t[idx] += value;

	while (idx > 1)
	{
		int prt = idx >> 1;
		if (idx % 2 == 0)
			t[prt] = t[idx] + t[idx + 1];
		else
			t[prt] = t[idx - 1] + t[idx];

		idx = prt;
	}
}

ll sum(int p, int q)
{
	p = si + p;
	q = si + q;

	ll rv = 0;
	while (p <= q)
	{
		if (p % 2 == 1)
			rv += t[p];

		if (q % 2 == 0)
			rv += t[q];

		p = (p + 1) >> 1;
		q = (q - 1) >> 1;
	}

	return rv;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	si = 1;
	while (si < n)
		si = si << 1;

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		switch (a)
		{
		case 1:
			replace(--b, c);
			break;
		case 2:
			cout << sum(--b, --c) << '\n';
			break;
		}
	}
}