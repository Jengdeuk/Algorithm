#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int minTime = 1000000;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
			continue;

		minTime = min(minTime, b);
	}

	if (minTime != 1000000)
		cout << minTime;
	else
		cout << -1;
}