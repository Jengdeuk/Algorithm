#include <iostream>
using namespace std;

bool c[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int k = 0; k < 4; ++k)
	{
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;
		for (int i = ax; i < bx; ++i)
			for (int j = ay; j < by; ++j)
				c[i][j] = true;
	}

	int cnt = 0;
	for (int i = 1; i <= 100; ++i)
		for (int j = 1; j <= 100; ++j)
			cnt += c[i][j];

	cout << cnt;
}