#include <iostream>
#include <cstring>
using namespace std;

int n, s[1001], v[1001];

void dfs(int start, int cur)
{
	if (v[cur])
		return;

	v[cur] = true;
	dfs(start, s[cur]);
}

void test()
{
	memset(v, false, sizeof(v));

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> s[i];

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (v[i] == false)
		{
			dfs(i, i);
			cnt++;
		}
	}

	cout << cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		test();
}