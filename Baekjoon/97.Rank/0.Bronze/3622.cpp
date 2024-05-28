#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, a, B, b, P;
	cin >> A >> a >> B >> b >> P;

	if (P >= A + B)
	{
		cout << "Yes";
		return 0;
	}

	if (P < A || P < B || A == B || a == b)
	{
		cout << "No";
		return 0;
	}

	if (A > B)
	{
		int Temp = A;
		A = B;
		B = Temp;

		Temp = a;
		a = b;
		b = Temp;
	}

	if (A > b)
	{
		cout << "No";
		return 0;
	}

	cout << "Yes";
}