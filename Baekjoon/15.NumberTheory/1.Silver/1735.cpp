#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	int C, D;
	cin >> C >> D;

	int Child, Parent;
	if (B == D)
	{
		Child = A + C;
		Parent = B;
	}
	else
	{
		Child = A * D + C * B;
		Parent = B * D;
	}

	int X = max(Child, Parent);
	int Y = min(Child, Parent);
	int Z;
	while (Y != 0)
	{
		Z = X % Y;
		X = Y;
		Y = Z;
	}

	Child /= X;
	Parent /= X;

	cout << Child << ' ' << Parent;
}