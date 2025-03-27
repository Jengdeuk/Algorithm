#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string sum(string l, string r)
{
	string value;

	int up = 0;
	for (int i = 0; i < l.size(); ++i)
	{
		int s = l[i] - '0' + r[i] - '0' + up;
		up = s / 10;
		s = s % 10;
		value.push_back(s + '0');
	}

	for (int i = l.size(); i < r.size(); ++i)
	{
		int s = r[i] - '0' + up;
		up = s / 10;
		s = s % 10;
		value.push_back(s + '0');
	}

	if (up > 0)
		value.push_back('1');

	return value;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string s[3];
	s[0] = "0";
	s[1] = "1";

	int n;
	cin >> n;
	if (n < 2)
	{
		cout << s[n];
		return 0;
	}

	int idx = 2, cnt = 2;
	while (true)
	{
		string value;
		switch (idx)
		{
		case 2:
			value = sum(s[0], s[1]);
			break;

		case 0:
			value = sum(s[1], s[2]);
			break;
			
		case 1:
			value = sum(s[2], s[0]);
			break;
		}

		s[idx] = value;

		if (cnt++ == n)
			break;

		if (++idx > 2)
			idx = 0;
	}

	reverse(s[idx].begin(), s[idx].end());

	cout << s[idx];
}