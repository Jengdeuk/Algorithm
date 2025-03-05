#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, f;
	cin >> n >> f;
	for (int i = 0; i < n - 1; ++i)
	{
		int r;
		cin >> r;

		int a = f, b = r;
		for (int j = min(f, r); j >= 2; --j)
		{
			if (f % j == 0 && r % j == 0)
			{
				a = f / j;
				b = r / j;
				break;
			}
		}
		cout << a << '/' << b << '\n';
	}
}