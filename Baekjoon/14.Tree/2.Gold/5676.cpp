#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, k, si;
int st[1 << 18];
queue<char> q;

void change(int x, int v)
{
	x += si;
	if (v == 0)
		v = 0;
	else if (v > 0)
		v = 1;
	else
		v = -1;

	st[x] = v;
	while (x > 1)
	{
		int p = x >> 1;
		if (x % 2 == 0)
			st[p] = st[x] * st[x + 1];
		else
			st[p] = st[x - 1] * st[x];

		x = p;
	}
}

void print(int l, int r)
{
	l += si;
	r += si;

	int s = 1;
	while (l <= r)
	{
		if (l % 2 == 1)
			s *= st[l];

		if (r % 2 == 0)
			s *= st[r];

		l = (l + 1) >> 1;
		r = (r - 1) >> 1;
	}

	if (s == 0)
		q.emplace('0');
	else if (s > 0)
		q.emplace('+');
	else
		q.emplace('-');
}

void test()
{
	memset(st, 1, sizeof(st));

	si = 1;
	while (si < n)
		si = si << 1;

	for (int i = si; i < si + n; ++i)
	{
		int num;
		cin >> num;
		if (num == 0)
			st[i] = 0;
		else if (num > 0)
			st[i] = 1;
		else
			st[i] = -1;
	}

	for (int i = si - 1; i >= 1; --i)
		st[i] = st[i * 2] * st[i * 2 + 1];

	for (int i = 0; i < k; ++i)
	{
		char command;
		int a, b;
		cin >> command >> a >> b;
		switch (command)
		{
		case 'C':
			change(a - 1, b);
			break;
		case 'P':
			print(a - 1, b - 1);
			break;
		}
	}

	while (q.empty() == false)
	{
		cout << q.front();
		q.pop();
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (cin >> n >> k)
		test();
}