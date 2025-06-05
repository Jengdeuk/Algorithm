#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	if (N >= 3)
	{
		if (M >= 7)
		{
			cout << M - 2;
		}
		else if (M >= 4)
		{
			cout << 4;
		}
		else
		{
			cout << M;
		}
	}
	else if (N == 2)
	{
		if (M >= 7)
		{
			cout << 4;
		}
		else if (M >= 5)
		{
			cout << 3;
		}
		else if (M >= 3)
		{
			cout << 2;
		}
		else
		{
			cout << 1;
		}
	}
	else
	{
		cout << 1;
	}
}