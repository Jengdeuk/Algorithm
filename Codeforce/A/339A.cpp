#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char chs[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string s;
	cin >> s;

	int n = 0;
	for (int i = 0; i < s.size(); i += 2)
	{
		chs[n++] = s[i];
	}

	sort(chs, chs + n);

	cout << chs[0];
	for (int i = 1; i < n; ++i)
	{
		cout << '+' << chs[i];
	}
}