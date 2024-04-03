#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i < N; ++i)
	{
		cout << ' ';
	}
	cout << '*';
	if (N == 1)
	{
		return 0;
	}
	cout << '\n';

	for (int i = 1; i < N - 1; ++i)
	{
		for (int j = 1; j <= N + i; ++j)
		{
			if (j == N - i|| j == N + i)
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}
		cout << '\n';
	}

	for (int i = 1; i < 2 * N; ++i)
	{
		cout << '*';
	}
}