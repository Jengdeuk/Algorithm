#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int M, D;
	cin >> M >> D;
	if (M == 2 && D == 18)
	{
		cout << "Special";
	}
	else if ((M == 2 && D < 18) || M == 1)
	{
		cout << "Before";
	}
	else
	{
		cout << "After";
	}
}