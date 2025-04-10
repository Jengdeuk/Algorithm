#include <iostream>
#include <string>
using namespace std;

int n, m[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j)
			m[i][j] = s[j];
	}

	int w = 0;
	for (int i = 0; i < n; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			if (m[i][j] == '.')
				w += (++cnt == 2);
			else
				cnt = 0;
		}
	}

	int h = 0;
	for (int j = 0; j < n; ++j)
	{
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			if (m[i][j] == '.')
				h += (++cnt == 2);
			else
				cnt = 0;
		}
	}

	cout << w << ' ' << h;
}