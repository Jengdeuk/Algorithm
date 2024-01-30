#include <iostream>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	int Hour = A;
	int Minute = B;

	Minute += C;
	Hour += Minute / 60;

	Minute %= 60;
	Hour %= 24;

	cout << Hour << ' ' << Minute;
}