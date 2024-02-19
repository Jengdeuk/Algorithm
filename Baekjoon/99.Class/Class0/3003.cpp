#include <iostream>
using namespace std;

int Complete[6] = { 1, 1, 2, 2, 2, 8 };
int Gap[6];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 6; ++i)
	{
		int Num;
		cin >> Num;
		Gap[i] = Complete[i] - Num;
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << Gap[i] << ' ';
	}
}