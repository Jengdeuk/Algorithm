#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int r = 0, c = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int num;
			cin >> num;
			if (num > 0)
			{
				r = i;
				c = j;
			}
		}
	}

	cout << abs(r - 2) + abs(c - 2);
}