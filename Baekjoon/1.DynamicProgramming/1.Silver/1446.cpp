#include <iostream>
#include <list>
using namespace std;

typedef pair<int, int> p;

list<p> pre[10001];
int dp[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, d;
	cin >> n >> d;
	while (n--)
	{
		int src, dst, cst;
		cin >> src >> dst >> cst;
		pre[dst].emplace_back(src, cst);
	}

	for (int i = 1; i <= d; ++i)
	{
		dp[i] = i;
	}

	int mcst = 10000;
	for (int i = 1; i <= d; ++i)
	{
		for (const p elem : pre[i])
		{
			int ncst = dp[elem.first] + elem.second;
			if (ncst < dp[i])
			{
				dp[i] = ncst;

				for (int j = i + 1; j <= d; ++j)
				{
					dp[j] = min(dp[j], dp[i] + (j - i));
				}
			}
		}

		mcst = min(mcst, dp[i] + (d - i));
	}
	
	cout << mcst;
}