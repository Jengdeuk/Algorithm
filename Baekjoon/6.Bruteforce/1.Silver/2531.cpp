#include <iostream>
using namespace std;

int n, d, k, c, m;
int belt[60000], eat[3001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> d >> k >> c;

	int num = 0, l = 0, r = 0;
	bool isCoupon = false;
	for (int i = 0; i < 2 * n; ++i)
	{
		r = i;
		if (i < n)
		{
			cin >> belt[i];
			belt[n + i] = belt[i];
		}

		if (eat[belt[i]]++ == 0)
			m = max(m, ++num);

		if (r - l + 1 < k)
		{
			if (isCoupon)
			{
				isCoupon = false;
				if (--eat[c] == 0)
					num--;
			}

			continue;
		}

		if (isCoupon == false)
		{
			isCoupon = true;
			if (eat[c]++ == 0)
				m = max(m, ++num);
		}

		if (--eat[belt[l++]] == 0)
			num--;
	}

	cout << m;
}