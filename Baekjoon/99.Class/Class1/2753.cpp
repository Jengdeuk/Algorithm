#include <iostream>
using namespace std;

int main()
{
	bool leap = true;

	int year = 0;
	cin >> year;

	if (year % 4 != 0)
	{
		leap = false;
	}

	if (year % 100 == 0
		&& year % 400 != 0)
	{
		leap = false;
	}

	if (leap)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
}