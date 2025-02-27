#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maximum = 1003001;

int prime[maximum + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 2; i <= maximum; ++i)
		prime[i] = true;

	for (int i = 2; i <= maximum; ++i)
	{
		if (prime[i] == false)
			continue;

		for (int j = 2; i * j <= maximum; ++j)
			prime[i * j] = false;
	}

	int n;
	cin >> n;
	for (int i = n; i <= maximum; ++i)
	{
		if (prime[i] == false)
			continue;

		string s = to_string(i);
		string rs = s;
		reverse(rs.begin(), rs.end());
		if (s.compare(rs) == 0)
		{
			cout << i;
			break;
		}
	}
}