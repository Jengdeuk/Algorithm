#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	while (cin >> n)
	{
		int num = 0;
		for (int i = 1; i <= n; ++i)
		{
			num = num * 10 + 1;
			if ((num %= n) == 0)
			{
				cout << i << '\n';
				break;
			}
		}
	}
}