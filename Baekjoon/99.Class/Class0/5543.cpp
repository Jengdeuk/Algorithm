#include <iostream>
using namespace std;

int Cost[5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 5; ++i)
	{
		cin >> Cost[i];
	}

	int Burger = min(min(Cost[0], Cost[1]), Cost[2]);
	int Drink = min(Cost[3], Cost[4]);

	cout << Burger + Drink - 50;
}