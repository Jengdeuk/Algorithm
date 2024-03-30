#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

ll GetValue(string Str)
{
	if (Str.compare("black") == 0)
	{
		return 0;
	}
	else if (Str.compare("brown") == 0)
	{
		return 1;
	}
	else if (Str.compare("red") == 0)
	{
		return 2;
	}
	else if (Str.compare("orange") == 0)
	{
		return 3;
	}
	else if (Str.compare("yellow") == 0)
	{
		return 4;
	}
	else if (Str.compare("green") == 0)
	{
		return 5;
	}
	else if (Str.compare("blue") == 0)
	{
		return 6;
	}
	else if (Str.compare("violet") == 0)
	{
		return 7;
	}
	else if (Str.compare("grey") == 0)
	{
		return 8;
	}
	else if (Str.compare("white") == 0)
	{
		return 9;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string A, B, C;
	cin >> A >> B >> C;

	ll Num = 0;
	Num += GetValue(A) * 10;
	Num += GetValue(B);
	Num *= pow(10LL, GetValue(C));

	cout << Num;
}