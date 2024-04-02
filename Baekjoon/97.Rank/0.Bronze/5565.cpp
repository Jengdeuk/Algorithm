#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Price;
	cin >> Price;
	for (int i = 0; i < 9; ++i)
	{
		int Num;
		cin >> Num;
		Price -= Num;
	}

	cout << Price;
}