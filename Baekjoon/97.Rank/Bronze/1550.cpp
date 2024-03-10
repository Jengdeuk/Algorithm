#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Str;
	cin >> Str;

	int Length = Str.length();
	int Sum = 0;
	for (int i = 0; i < Length; ++i)
	{
		char Ch = Str[Length - 1 - i];
		int Num;
		if (Ch >= 'A')
		{
			Num = Ch - 'A' + 10;
		}
		else
		{
			Num = Ch - '0';
		}
		Sum += Num * pow(16, i);
	}

	cout << Sum;
}