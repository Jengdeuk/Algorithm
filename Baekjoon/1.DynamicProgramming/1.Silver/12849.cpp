#include <iostream>
using namespace std;

typedef long long ll;

const int Mod = 1e9 + 7;

ll DP[8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int D;
	cin >> D;

	DP[0] = 1;
	for (int i = 0; i < D; ++i)
	{
		ll DP0 = (DP[1] + DP[2]) % Mod;
		ll DP1 = (DP[0] + DP[2] + DP[3]) % Mod;
		ll DP2 = (DP[0] + DP[1] + DP[3] + DP[4]) % Mod;
		ll DP3 = (DP[1] + DP[2] + DP[4] + DP[5]) % Mod;
		ll DP4 = (DP[2] + DP[3] + DP[5] + DP[7]) % Mod;
		ll DP5 = (DP[3] + DP[4] + DP[6]) % Mod;
		ll DP6 = (DP[5] + DP[7]) % Mod;
		ll DP7 = (DP[4] + DP[6]) % Mod;

		DP[0] = DP0;
		DP[1] = DP1;
		DP[2] = DP2;
		DP[3] = DP3;
		DP[4] = DP4;
		DP[5] = DP5;
		DP[6] = DP6;
		DP[7] = DP7;
	}

	cout << DP[0];
}