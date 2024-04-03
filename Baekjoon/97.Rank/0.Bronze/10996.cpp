#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	if (N == 1)
	{
		cout << '*';
		return 0;
	}

	for (int i = 0; i < 2 * N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					cout << '*';
				}
				else
				{
					cout << ' ';
				}
			}
			else
			{
				if (j % 2 == 1)
				{
					cout << '*';
				}
				else
				{
					cout << ' ';
				}
			}
		}
		cout << '\n';
	}
}