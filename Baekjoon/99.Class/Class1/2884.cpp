#include <iostream>
using namespace std;

int main()
{
	int hour = 0, minute = 0;
	cin >> hour >> minute;

	int modifyTime = hour * 60 + minute - 45;
	if (modifyTime < 0)
	{
		modifyTime = 24 * 60 + modifyTime;
	}

	int modifyHour = modifyTime / 60;
	int modifyMinute = modifyTime % 60;
	cout << modifyHour << ' ' << modifyMinute;
}