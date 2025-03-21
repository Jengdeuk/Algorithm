#include <iostream>
using namespace std;

int n, s[100000];

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> s[0];

	int gap;
	for (int i = 1; i < n; ++i)
	{
		cin >> s[i];

		int g = s[i] - s[i - 1];
		if (i == 1)
			gap = g;
		else
			gap = gcd(max(g, gap), min(g, gap));
	}

	int cnt = 0;
	for (int i = 1; i < n; ++i)
		cnt += (s[i] - s[i - 1]) / gap - 1;

	cout << cnt;
}