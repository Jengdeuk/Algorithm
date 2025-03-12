#include <iostream>
#include <algorithm>
using namespace std;

int n, s[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	sort(s, s + n, greater<>());

	for (int i = 0; i < n; ++i)
		cout << s[i] << '\n';
}