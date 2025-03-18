#include <iostream>
#include <queue>
using namespace std;

void test()
{
	int n;
	cin >> n;
	cout << n / 2 + 1 << '\n';

	priority_queue<int> uq;
	priority_queue<int, vector<int>, greater<int>> lq;
	int pi = 0;
	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;
		if (lq.empty() == false && num > lq.top())
		{
			uq.emplace(lq.top());
			lq.pop();
			lq.emplace(num);
		}
		else
		{
			uq.emplace(num);
		}

		if (i % 2 == 1)
		{
			int size = i / 2 + 1;
			while (uq.size() > size)
			{
				lq.emplace(uq.top());
				uq.pop();
			}

			cout << uq.top() << ' ';
			if (++pi == 10)
			{
				pi = 0;
				cout << '\n';
			}
		}
	}

	if (pi < 10)
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