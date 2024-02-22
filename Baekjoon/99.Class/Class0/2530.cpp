#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A, B, C, D, Carry;
	cin >> A >> B >> C >> D;

	C += D;
	Carry = C / 60;
	C %= 60;

	B += Carry;
	Carry = B / 60;
	B %= 60;

	A += Carry;
	A %= 24;

	cout << A << ' ' << B << ' ' << C;
}