#include <iostream>
using namespace std;

const double PI = 3.1415926535897;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B, H;
	cin >> A >> B >> H;

	cout << fixed;
	cout.precision(7);

	if (A == 0)
	{
		cout << (H * H + B * B) * PI;
		return 0;
	}

	if (A == B)
	{
		cout << -1;
		return 0;
	}

	if (A > B)
	{
		int Temp = A;
		A = B;
		B = Temp;
	}

	double R1 = H / (double(B) / A - 1);
	double R2 = double(B) / A * R1;

	double C1 = (R1 * R1 + A * A) * PI;
	double C2 = (R2 * R2 + B * B) * PI;

	cout << C2 - C1;
}