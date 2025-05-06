#include <iostream>
#include <algorithm>
using namespace std;

int n, s[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int l;
	cin >> n >> l;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	sort(s, s + n);

	for (int i = 0; i < n; ++i)
	{
		if (l >= s[i])
			l++;
		else
			break;
	}

	cout << l;
}