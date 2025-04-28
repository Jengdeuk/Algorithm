#include <iostream>
using namespace std;

int n, org[10000];

bool v[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> org[i];

	bool isFindIdx = false;
	int idx = 0;
	for (int i = n - 1; i > 0; --i)
	{
		v[org[i]] = true;
		if (org[i - 1] > org[i])
		{
			isFindIdx = true;
			v[org[i - 1]] = true;

			int cur = org[i - 1] - 1;
			while (v[cur] == false)
				cur--;

			org[i - 1] = cur;
			v[cur] = false;

			idx = i;
			break;
		}
	}

	if (isFindIdx)
	{
		for (int i = 0; i < idx; ++i)
			cout << org[i] << ' ';

		for (int i = n; i >= 1; --i)
			if (v[i])
				cout << i << ' ';
	}
	else
	{
		cout << -1;
	}
}