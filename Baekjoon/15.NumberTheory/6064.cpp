#include <iostream>
using namespace std;

int GCD(int A, int B)
{
	if (B == 0)
	{
		return A;
	}

	return GCD(B, A % B);
}

int LCM(int A, int B)
{
	return (A * B) / GCD(A, B);
}

void Test()
{
	int M, N, X, Y;
	cin >> M >> N >> X >> Y;

	int MaxYear = LCM(M, N);
	for (int Year = X; Year <= MaxYear; Year += M)
	{
		int Remainder = Year % N;

		if (Remainder == 0)
		{
			Remainder = N;
		}

		if (Remainder == Y)
		{
			cout << Year << '\n';
			return;
		}
	}

	cout << -1 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}