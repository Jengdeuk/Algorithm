#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < 2 * N; ++i)
	{
		int Star;
		if (i < N)
		{
			Star = i + 1;
		}
		else
		{
			Star = 2 * N - 1 - i;
		}

		int Blank = 2 * N - 2 * Star;

		for (int j = 0; j < Star; ++j)
		{
			cout << '*';
		}

		for (int j = 0; j < Blank; ++j)
		{
			cout << ' ';
		}

		for (int j = 0; j < Star; ++j)
		{
			cout << '*';
		}

		cout << '\n';
	}
}