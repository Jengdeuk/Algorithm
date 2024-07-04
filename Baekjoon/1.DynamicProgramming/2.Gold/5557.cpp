#include <iostream>
using namespace std;

typedef long long ll;

int N;
ll DP[100][21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; ++i)
	{
		int Num;
		cin >> Num;

		if (i == 0)
		{
			DP[i][Num] = 1;
			continue;
		}

		for (int j = 0; j <= 20; ++j)
		{
			if (j + Num <= 20)
			{
				DP[i][j + Num] += DP[i - 1][j];
			}

			if (j - Num >= 0)
			{
				DP[i][j - Num] += DP[i - 1][j];
			}
		}
	}

	int Fin;
	cin >> Fin;
	cout << DP[N - 2][Fin];
}