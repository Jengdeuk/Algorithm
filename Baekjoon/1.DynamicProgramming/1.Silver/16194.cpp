#include <iostream>
using namespace std;

int p[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
		for (int j = 1; j < i; ++j)
			p[i] = min(p[i], p[i - j] + p[j]);
	}

	cout << p[n];
}