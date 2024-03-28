#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int X;
	cin >> X;

	int Cnt = 0;
	while (X)
	{
		Cnt += (X & 1);
		X >>= 1;
	}

	cout << Cnt;
}