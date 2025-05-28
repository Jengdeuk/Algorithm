#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int j;
	cin >> j;

	int sum = 0, l = 1, r = l + m - 1;
	while (j--)
	{
		int num;
		cin >> num;

		int cnt = 0;
		if (num < l)
		{
			cnt = l - num;
			l -= cnt;
			r -= cnt;
		}
		else if (num > r)
		{
			cnt = num - r;
			l += cnt;
			r += cnt;
		}

		sum += cnt;
	}

	cout << sum;
}