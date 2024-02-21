#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	if (A == 60 && B == 60 && C == 60)
	{
		cout << "Equilateral";
	}
	else if (A + B + C == 180
		&& (A == B || B == C || C == A))
	{
		cout << "Isosceles";
	}
	else if (A + B + C == 180
		&& (A != B && B != C && C != A))
	{
		cout << "Scalene";
	}
	else if (A + B + C != 180)
	{
		cout << "Error";
	}
}