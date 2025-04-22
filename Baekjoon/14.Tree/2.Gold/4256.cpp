#include <iostream>
using namespace std;

int n, pre[1000], ino[1000];

void dfs(int pi, int s, int e)
{
	if (s >= e)
		return;

	int ii = 0;
	for (int i = s; i < e; ++i)
	{
		if (ino[i] == pre[pi])
		{
			ii = i;
			break;
		}
	}

	dfs(pi + 1, s, ii);
	dfs(pi + 1 + ii - s, ii + 1, e);
	cout << pre[pi] << ' ';
}

void test()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> pre[i];

	for (int i = 0; i < n; ++i)
		cin >> ino[i];

	dfs(0, 0, n);
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) test();
}