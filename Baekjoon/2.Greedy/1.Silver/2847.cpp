#include <iostream>
using namespace std;

int n, s[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	int cnt = 0;
	for (int i = n - 2; i >= 0; --i)
	{
		if (s[i] >= s[i + 1])
		{
			cnt += s[i] - s[i + 1] + 1;
			s[i] = s[i + 1] - 1;
		}
	}

	cout << cnt;
}