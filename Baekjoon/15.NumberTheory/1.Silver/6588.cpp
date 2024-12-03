#include <iostream>
using namespace std;

bool P[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 2; i <= 1000000; ++i)
	{
		P[i] = true;
	}

	for (int i = 2; i <= 500000; ++i)
	{
		if (!P[i])
		{
			continue;
		}

		for (int j = 2; i * j <= 1000000; ++j)
		{
			P[i * j] = false;
		}
	}

	while (true)
	{
		int N;
		cin >> N;
		if (N == 0)
		{
			break;
		}

		int I = 3;
		while (I < N && (!P[I] || !P[N - I]))
		{
			I += 2;
		}

		if (P[I] && P[N - I])
		{
			cout << N << " = " << I << " + " << N - I << '\n';
		}
		else
		{
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
}