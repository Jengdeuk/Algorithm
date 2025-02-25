#include <iostream>
using namespace std;

int n, w[10][10], v[10];
int minCost = 123456789;

bool isFinished()
{
	for (int i = 0; i < n; ++i)
		if (v[i] == false)
			return false;

	return true;
}

void bf(int cost, int start, int cur)
{
	if (isFinished())
	{
		if (w[cur][start] > 0)
			minCost = min(minCost, cost + w[cur][start]);

		return;
	}

	if (cost >= minCost)
		return;

	for (int i = 0; i < n; ++i)
	{
		if (v[i] || w[cur][i] == 0)
			continue;

		v[i] = true;
		bf(cost + w[cur][i], start, i);
		v[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> w[i][j];

	for (int i = 0; i < n; ++i)
	{
		v[i] = true;
		bf(0, i, i);
		v[i] = false;
	}

	cout << minCost;
}