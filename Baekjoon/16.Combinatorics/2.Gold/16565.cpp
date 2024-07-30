#include <iostream>
using namespace std;

const int Mod = 10007;

int C[53][53];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int n = 0; n <= 52; n++) {
		C[n][0] = 1;
		C[n][n] = 1;
		for (int k = 1; k < n; k++) {
			C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
			C[n][k] %= Mod;
			C[n][n - k] = C[n][k];
		}
	}

	int N;
	cin >> N;

	int Sum = 0;
	for (int i = 4; i <= N; i += 4)
	{
		if (i / 4 % 2)
		{
			Sum += C[13][i / 4] * C[52 - i][N - i];
			Sum %= Mod;
		}
		else
		{
			Sum -= C[13][i / 4] * C[52 - i][N - i];
			Sum %= Mod;
		}
	}

	if (Sum < 0)
	{
		Sum += Mod;
	}

	cout << Sum;
}