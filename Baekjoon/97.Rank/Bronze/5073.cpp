#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		int A, B, C;
		cin >> A >> B >> C;

		if (A == 0 && B == 0 && C == 0)
		{
			break;
		}

		if (A == B && B == C && C == A)
		{
			cout << "Equilateral\n";
			continue;
		}

		int Max = max(max(A, B), C);
		if (A + B + C - 2 * Max <= 0)
		{
			cout << "Invalid\n";
			continue;
		}
		
		if (A == B || B == C || C == A)
		{
			cout << "Isosceles\n";
			continue;
		}

		cout << "Scalene\n";
	}
}