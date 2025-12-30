#include <iostream>
#include <string>
using namespace std;

const int conv[11] = { 0, 7, 4, 1, 8, 5, 2, 9, 6, 3, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string s;
	cin >> s;

	int sum = 0, idx = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != '*')
		{
			sum += (i % 2 == 0 ? 1 : 3) * (s[i] - '0');
		}
		else
		{
			idx = i;
		}
	}

	int x = 10 - sum % 10;
	if (idx % 2 || x == 10)
	{
		x = conv[x];
	}

	cout << x;
}