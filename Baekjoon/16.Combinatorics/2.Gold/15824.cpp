#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const ll Mod = 1000000007;

int N;
ll S[300000], P[300000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
		if (i == 0)
		{
			P[i] = 1;
			continue;
		}

		P[i] = P[i - 1] * 2;
		P[i] %= Mod;
	}
	
	sort(S, S + N, greater<>());

	ll Add = 0, Sub = 0;
	for (int i = 0; i < N; ++i)
	{
		Add += S[i] * (P[(N - 1) - i] - 1);
		Add %= Mod;
		Sub += S[i] * (P[i] - 1);
		Sub %= Mod;
	}

	cout << (Add + Mod - Sub) % Mod;
}