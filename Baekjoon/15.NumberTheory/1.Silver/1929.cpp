#include <iostream>
using namespace std;

bool PrimeNumber[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	for (int i = 2; i <= N; ++i)
	{
		PrimeNumber[i] = true;
	}

	for (int i = 2; i <= N; ++i)
	{
		if (!PrimeNumber[i])
		{
			continue;
		}

		for (int j = 2; i * j <= N; ++j)
		{
			PrimeNumber[i * j] = false;
		}
	}

	for (int i = M; i <= N; ++i)
	{
		if (!PrimeNumber[i])
		{
			continue;
		}

		cout << i << '\n';
	}
}