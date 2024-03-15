#include <iostream>
using namespace std;

bool Prime[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 2; i <= 10000; ++i)
	{
		Prime[i] = true;
	}

	for (int i = 2; i <= 5000; ++i)
	{
		if (!Prime[i])
		{
			continue;
		}

		for (int j = 2; j * i <= 10000; ++j)
		{
			Prime[j * i] = false;
		}
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;

		for (int j = N / 2; j >= 2; --j)
		{
			int k = N - j;
			if (Prime[j] && Prime[k])
			{
				cout << j << ' ' << k << '\n';
				break;
			}
		}
	}
}