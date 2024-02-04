#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int FactorialN = 1;
	for (int i = N; i > 0; --i)
	{
		FactorialN *= i;
	}

	int FactorialK = 1;
	for (int i = K; i > 0; --i)
	{
		FactorialK *= i;
	}

	int FactorialNK = 1;
	for (int i = N - K; i > 0; --i)
	{
		FactorialK *= i;
	}

	cout << FactorialN / (FactorialK * FactorialNK);
}