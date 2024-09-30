#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int X, Y;
	cin >> X >> Y;
	int Z = double(Y) * 100 / X;
	if (Z == 100 || Z == 99)
	{
		cout << -1;
		return 0;
	}

	int Answer = 0;
	int L = 0, R = 1000000000;
	while (L <= R)
	{
		int M = (L + R) / 2;
		if (int(double(Y + M) * 100 / (X + M)) >= Z + 1)
		{
			Answer = M;
			R = M - 1;
		}
		else
		{
			L = M + 1;
		}
	}

	cout << Answer;
}