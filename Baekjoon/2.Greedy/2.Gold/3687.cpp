#include <iostream>
#include <climits>
#include <deque>
#include <string>
using namespace std;

const long long inf = LLONG_MAX;

const int cost[10] =
{
	6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};

const char minNum[8] =
{
	'0', '0', '1', '7', '4', '2', '0', '8'
};

int n;
string dp[101];

void test()
{
	cin >> n;
	cout << dp[n] << ' ';

	deque<int> q;

	int cur = n;
	while (cur > 0 && cur != 3)
	{
		cur -= cost[1];
		q.emplace_front(1);
	}

	if (cur > 0)
	{
		cur -= cost[7];
		q.emplace_front(7);
	}

	while (q.empty() == false)
	{
		cout << q.front();
		q.pop_front();
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i <= 100; ++i)
	{
		dp[i] = to_string(inf);
	}

	for (int i = 2; i < 8; ++i)
	{
		dp[i] = minNum[i];
	}
	dp[6] = '6';

	for (int i = 8; i <= 100; ++i)
	{
		for (int j = 2; j <= 7; ++j)
		{
			if (stoll(dp[i - j]) != inf && stoll(dp[i - j] + minNum[j]) < stoll(dp[i]))
			{
				dp[i] = dp[i - j] + minNum[j];
			}
		}
	}

	int t;
	cin >> t;
	while (t--) test();
}