#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, d, k, c;
	cin >> n >> d >> k >> c;

	vector<int> belt(n, 0);
	for (int i = 0; i < n; ++i)
	{
		cin >> belt[i];
	}

	vector<int> eat(d + 1, 0);

	int cnt = 0;
	for (int i = 0; i < k; ++i)
	{
		if (eat[belt[i]]++ == 0)
		{
			cnt++;
		}
	}

	if (eat[c]++ == 0)
	{
		cnt++;
	}

	int answer = cnt;
	for (int i = 1; i < n; ++i)
	{
		int l = i - 1;
		if (--eat[belt[l]] == 0)
		{
			cnt--;
		}

		int r = (i + k - 1) % n;
		if (eat[belt[r]]++ == 0)
		{
			cnt++;
		}

		answer = max(answer, cnt);
	}

	cout << answer;
}