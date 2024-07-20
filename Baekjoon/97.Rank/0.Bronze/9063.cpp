#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int mX = 10000, MX = -10000, mY = 10000, MY = -10000;
	for (int i = 0; i < N; ++i)
	{
		int X, Y;
		cin >> X >> Y;

		mX = min(mX, X);
		MX = max(MX, X);
		mY = min(mY, Y);
		MY = max(MY, Y);
	}

	if (N > 1)
	{
		cout << (MX - mX) * (MY - mY);
	}
	else
	{
		cout << 0;
	}
}