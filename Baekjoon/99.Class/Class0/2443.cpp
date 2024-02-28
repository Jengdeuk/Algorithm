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
		for (int j = 0; j < i; ++j)
		{
			cout << ' ';
		}

		int Star = (2 * N - 1) - 2 * i;
		for (int j = 0; j < Star; ++j)
		{
			cout << '*';
		}

		cout << '\n';
	}
}