#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	
	int Size = 2 * N;
	for (int i = 0; i < Size; ++i)
	{
		int Star;
		if (i < Size / 2)
		{
			Star = 1 + 2 * i;
		}
		else
		{
			Star = (Size - 1) - 2 * (i + 1 - Size / 2);
		}

		for (int j = (Size - 1 - Star) / 2; j > 0; --j)
		{
			cout << ' ';
		}

		for (int j = Star; j > 0; --j)
		{
			cout << '*';
		}

		cout << '\n';
	}
}