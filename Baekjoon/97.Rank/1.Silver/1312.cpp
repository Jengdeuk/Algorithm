#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B, N;
	cin >> A >> B >> N;

	int C = 0;
	if (A % B != 0)
	{
		A = A % B;

		while (N--)
		{
			A *= 10;
			C = A / B;
			A = A % B;
		}
	}

	cout << C;
}