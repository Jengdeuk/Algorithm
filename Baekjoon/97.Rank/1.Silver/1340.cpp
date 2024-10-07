#include <iostream>
#include <string>
using namespace std;

const int YMD[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int NMD[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Y, M, D, H, S;
	string SM, SD, ST;
	cin >> SM >> SD >> Y >> ST;

	if (SM.compare("January") == 0)
	{
		M = 0;
	}
	else if (SM.compare("February") == 0)
	{
		M = 1;
	}
	else if (SM.compare("March") == 0)
	{
		M = 2;
	}
	else if (SM.compare("April") == 0)
	{
		M = 3;
	}
	else if (SM.compare("May") == 0)
	{
		M = 4;
	}
	else if (SM.compare("June") == 0)
	{
		M = 5;
	}
	else if (SM.compare("July") == 0)
	{
		M = 6;
	}
	else if (SM.compare("August") == 0)
	{
		M = 7;
	}
	else if (SM.compare("September") == 0)
	{
		M = 8;
	}
	else if (SM.compare("October") == 0)
	{
		M = 9;
	}
	else if (SM.compare("November") == 0)
	{
		M = 10;
	}
	else if (SM.compare("December") == 0)
	{
		M = 11;
	}

	D = stoi(SD.substr(0, 2));
	H = stoi(ST.substr(0, 2));
	S = stoi(ST.substr(3, 2));

	long double Total;
	bool bY = false;
	if (Y % 400 == 0 || (Y % 4 == 0 && Y % 100 != 0))
	{
		bY = true;
		Total = 366 * 24 * 60;
	}
	else
	{
		Total = 365 * 24 * 60;
	}

	long double Current = 0;
	for (int i = 0; i < M; ++i)
	{
		if (bY)
		{
			Current += YMD[i] * 24 * 60;
		}
		else
		{
			Current += NMD[i] * 24 * 60;
		}
	}

	Current += (D - 1) * 24 * 60 + H * 60 + S;

	cout.precision(17);
	cout << Current * 100 / Total;
}