#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int n, m;

void test()
{
	cin >> n;

	int m;
	cin >> m;

	priority_queue<p> q;
	for (int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		q.emplace(a, b);
	}

	bool book[1001] = {};
	while (q.empty() == false)
	{
		int a = q.top().first;
		int b = q.top().second;
		q.pop();

		for (int i = b; i >= a; --i)
		{
			if (book[i] == false)
			{
				book[i] = true;
				break;
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		if (book[i])
			cnt++;

	cout << cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) test();
}