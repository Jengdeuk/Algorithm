#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415926535897;
const double G = 9.81;

double Radian(double Angle)
{
	return Angle * (PI / 180);
}

void Test()
{
	double V, A, X, H1, H2;
	cin >> V >> A >> X >> H1 >> H2;

	A = Radian(A);
		
	double T = X / (V * cos(A));
	double Y = V * T * sin(A) - 0.5 * G * T * T;

	if (Y >= H1 + 1 && Y <= H2 - 1)
	{
		cout << "Safe\n";
	}
	else
	{
		cout << "Not Safe\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		Test();
	}
}