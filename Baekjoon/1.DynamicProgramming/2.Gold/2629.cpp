#include <iostream>
using namespace std;

int n, w[30];
bool dp[31][15001];

void f(int idx, int wgt)
{
	if (idx > n || dp[idx][wgt])
		return;

	dp[idx][wgt] = true;
	if (idx == n)
		return;

	f(idx + 1, wgt + w[idx]);
	f(idx + 1, abs(wgt - w[idx]));
	f(idx + 1, wgt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> w[i];

	f(0, 0);

	int m;
	cin >> m;
	while (m--)
	{
		int wgt;
		cin >> wgt;
		if (wgt <= 15000 && dp[n][wgt])
			cout << "Y ";
		else
			cout << "N ";
	}
}