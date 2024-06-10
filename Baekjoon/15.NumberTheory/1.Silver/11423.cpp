#include <iostream>
using namespace std;

bool P[10000001];
int S[10000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 2; i <= 10000000; ++i)
	{
		P[i] = true;
	}

	for (int i = 2; i <= 10000000; ++i)
	{
		if (!P[i])
		{
			continue;
		}

		for (int j = 2; j * i <= 10000000; ++j)
		{
			P[j * i] = false;
		}
	}

	for (int i = 2; i <= 10000000; ++i)
	{
		S[i] = S[i - 1] + P[i];
	}

	while (true)
	{
		int M = 0, N = 0;
		cin >> M >> N;
		if (M == 0 && N == 0)
		{
			break;
		}

		cout << S[N] - S[M - 1] << "\n\n";
	}
}