#include <iostream>
using namespace std;

int n, k;
char m[20000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> m[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (m[i] != 'P')
		{
			continue;
		}

		for (int j = i - k; j < i + k + 1 && j < n; ++j)
		{
			if (j < 0 || m[j] != 'H')
			{
				continue;
			}

			m[j] = '-';
			cnt++;
			break;
		}
	}
	
	cout << cnt;
}