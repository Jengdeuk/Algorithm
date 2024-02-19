#include <iostream>
using namespace std;

int N[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int Input;
	cin >> Input;

	N[0] = Input / 10;
	N[1] = Input % 10;

	int CycleLength = 1;
	int Temp = N[1];
	N[1] = (N[0] + N[1]) % 10;
	N[0] = Temp;
	int Num = N[0] * 10 + N[1];

	while (Num != Input)
	{
		Temp = N[1];
		N[1] = (N[0] + N[1]) % 10;
		N[0] = Temp;

		Num = N[0] * 10 + N[1];
		++CycleLength;
	}

	cout << CycleLength;
}