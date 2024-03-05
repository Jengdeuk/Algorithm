#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < 2 * N - 1; ++i)
	{
		int Star = N - abs(N - 1 - i);

		for (int i = 0; i < Star; ++i)
		{
			cout << '*';
		}

		cout << '\n';
	}
}