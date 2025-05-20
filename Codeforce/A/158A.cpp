#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	int cnt = 0, kScore = 0;
	for (int i = 1; i <= n; ++i)
	{
		int score;
		cin >> score;
		if (score > 0 && i <= k)
		{
			cnt++;
			if (i == k)
			{
				kScore = score;
			}

			continue;
		}

		if (score > 0 && score >= kScore)
		{
			cnt++;
		}
	}

	cout << cnt;
}