#include <iostream>
using namespace std;

int n, k, a[500000], tmp[500000];
int cnt, answer;

void merge(int p, int q, int r)
{
	int i = p, j = q + 1, t = 0;
	while (i <= q && j <= r)
	{
		if (a[i] <= a[j])
		{
			tmp[t++] = a[i++];
		}
		else
		{
			tmp[t++] = a[j++];
		}
	}

	while (i <= q)
	{
		tmp[t++] = a[i++];
	}

	while (j <= r)
	{
		tmp[t++] = a[j++];
	}

	i = p, t = 0;
	while (i <= r)
	{
		if (++cnt == k)
		{
			answer = tmp[t];
		}
		a[i++] = tmp[t++];
	}
}

void merge_sort(int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	merge_sort(0, n - 1);

	if (answer > 0)
		cout << answer;
	else
		cout << -1;
}