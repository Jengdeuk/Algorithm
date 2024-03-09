#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Star = i + 1;
		int Blank = N - Star;

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

	for (int i = 0; i < N; ++i)
	{
		int Star = N - (i + 1);
		int Blank = N - Star;

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