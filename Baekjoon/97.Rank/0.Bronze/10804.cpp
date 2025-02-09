#include <iostream>
#include <algorithm>
using namespace std;

int c[20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 20; ++i)
		c[i] = i + 1;

	for (int i = 0; i < 10; ++i)
	{
		int a, b;
		cin >> a >> b;
		reverse(c + a - 1, c + b);
	}

	for (int i = 0; i < 20; ++i)
		cout << c[i] << ' ';
}