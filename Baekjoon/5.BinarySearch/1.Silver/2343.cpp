#include <iostream>
using namespace std;

int n, k;
int s[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	
	int l = 0, r = 0;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;

		s[i] = num;
		l = max(l, num);
		r += num;
	}
	
	int answer = r;
	while (l <= r)
	{
		int m = (l + r) / 2;
		int cnt = 0, sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (sum == 0)
				++cnt;

			int nsum = sum + s[i];
			if (nsum < m)
			{
				sum = nsum;
			}
			else if (nsum == m)
			{
				sum = 0;
			}
			else
			{
				++cnt;
				sum = s[i];
			}
		}

		if (cnt <= k)
		{
			answer = min(answer, m);
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}

	cout << answer;
}