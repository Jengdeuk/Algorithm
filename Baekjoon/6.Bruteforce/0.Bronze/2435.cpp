#include <iostream>
using namespace std;

int n, k, s[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	int ms = -100000;
	for (int i = 0; i < n - k + 1; ++i)
	{
		int sum = 0;
		for (int j = i; j < i + k; ++j)
			sum += s[j];

		ms = max(ms, sum);
	}

	cout << ms;
}