#include <iostream>
using namespace std;

const int Mod = 9901;

int N;
int DP[100000][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	DP[0][0] = 1;
	DP[0][1] = 1;
	DP[0][2] = 1;
	for (int i = 1; i < N; ++i)
	{
		DP[i][0] = (DP[i - 1][0] + DP[i - 1][1] + DP[i - 1][2]) % Mod;
		DP[i][1] = (DP[i - 1][0] + DP[i - 1][2]) % Mod;
		DP[i][2] = (DP[i - 1][0] + DP[i - 1][1]) % Mod;
	}

	cout << (DP[N - 1][0] + DP[N - 1][1] + DP[N - 1][2]) % Mod;
}