#include <iostream>
using namespace std;

typedef pair<int, int> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	p s[10];
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i].first >> s[i].second;
	}

	const int maxBit = (1 << n);

	int bit = 1;
	int minGap = 1000000000;
	while (bit < maxBit)
	{
		int a = 1;
		int b = 0;
		for (int i = 0; i < n; ++i)
		{
			if (bit & (1 << i))
			{
				a *= s[i].first;
				b += s[i].second;
			}
		}

		minGap = min(minGap, abs(a - b));

		++bit;
	}

	cout << minGap;
}