#include <iostream>
using namespace std;

int CntA, CntB;
int DP[41];

int Fib(int N)
{
	if (N == 1 || N == 2)
	{
		++CntA;
		return 1;
	}

	return Fib(N - 1) + Fib(N - 2);
}

int Fib_DP(int N)
{
	DP[1] = 1, DP[2] = 1;
	for (int i = 3; i <= N; ++i)
	{
		++CntB;
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	return DP[N];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	Fib(N);
	Fib_DP(N);

	cout << CntA << ' ' << CntB;
}