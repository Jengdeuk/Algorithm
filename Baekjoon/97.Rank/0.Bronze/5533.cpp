#include <iostream>
using namespace std;

int n;
int s[200][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)	
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> s[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			bool bSameScore = false;
			for (int k = 0; k < n; ++k)
			{
				if (k == i)
				{
					continue;
				}

				if (s[k][j] == s[i][j])
				{
					bSameScore = true;
					break;
				}
			}

			if (!bSameScore)
			{
				s[i][3] += s[i][j];
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << s[i][3] << '\n';
	}
}