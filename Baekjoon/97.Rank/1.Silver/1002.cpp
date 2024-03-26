#include <iostream>
#include <cmath>
using namespace std;

void Test()
{
	int X1, Y1, R1, X2, Y2, R2;
	cin >> X1 >> Y1 >> R1 >> X2 >> Y2 >> R2;

	int D = (X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2);

	int Case1 = (R1 - R2) * (R1 - R2);
	int Case2 = (R1 + R2) * (R1 + R2);

	if (D == 0 && R1 == R2)
	{
		cout << -1 << '\n';
	}
	else if (Case1 == D || Case2 == D)
	{
		cout << 1 << '\n';
	}
	else if (Case1 < D && D < Case2)
	{
		cout << 2 << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}