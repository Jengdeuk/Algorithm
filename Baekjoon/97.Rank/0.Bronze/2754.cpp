#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Grade;
	cin >> Grade;

	if (Grade.compare("A+") == 0)
	{
		cout << "4.3";
	}
	else if (Grade.compare("A0") == 0)
	{
		cout << "4.0";
	}
	else if (Grade.compare("A-") == 0)
	{
		cout << "3.7";
	}
	else if (Grade.compare("B+") == 0)
	{
		cout << "3.3";
	}
	else if (Grade.compare("B0") == 0)
	{
		cout << "3.0";
	}
	else if (Grade.compare("B-") == 0)
	{
		cout << "2.7";
	}
	else if (Grade.compare("C+") == 0)
	{
		cout << "2.3";
	}
	else if (Grade.compare("C0") == 0)
	{
		cout << "2.0";
	}
	else if (Grade.compare("C-") == 0)
	{
		cout << "1.7";
	}
	else if (Grade.compare("D+") == 0)
	{
		cout << "1.3";
	}
	else if (Grade.compare("D0") == 0)
	{
		cout << "1.0";
	}
	else if (Grade.compare("D-") == 0)
	{
		cout << "0.7";
	}
	else
	{
		cout << "0.0";
	}
}