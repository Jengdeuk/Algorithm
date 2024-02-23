#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int X1, X2, X3, X4;
	int Y1, Y2, Y3, Y4;

	cin >> X1 >> Y1;
	cin >> X2 >> Y2;
	cin >> X3 >> Y3;

	if (X1 == X2)
	{
		X4 = X3;
	}
	else if (X2 == X3)
	{
		X4 = X1;
	}
	else if (X3 == X1)
	{
		X4 = X2;
	}

	if (Y1 == Y2)
	{
		Y4 = Y3;
	}
	else if (Y2 == Y3)
	{
		Y4 = Y1;
	}
	else if (Y3 == Y1)
	{
		Y4 = Y2;
	}

	cout << X4 << ' ' << Y4;
}