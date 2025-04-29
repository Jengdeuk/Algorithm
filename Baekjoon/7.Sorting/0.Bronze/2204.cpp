#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string o[1000], s[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; ++i)
		{
			cin >> o[i];
			s[i] = o[i];
			for (int j = 0; j < s[i].size(); ++j)
				if (s[i][j] >= 'a')
					s[i][j] -= 32;
		}

		cout << o[min_element(s, s + n) - s] << '\n';
	}
}