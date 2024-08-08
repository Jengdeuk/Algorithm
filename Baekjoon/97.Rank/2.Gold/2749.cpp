#include <iostream>
#include <map>
using namespace std;

typedef long long ll;

const int Mod = 1000000;

map<ll, ll> M;

ll F(ll X)
{
	if (X == 0)
	{
		return 0;
	}
	else if (X == 1 || X == 2)
	{
		return 1;
	}
	else if (M.count(X) > 0)
	{
		return M[X];
	}

	ll FUp, FDown;
	if (X % 2 == 0)
	{
		FUp = F(X / 2);
		FDown = F(X / 2 - 1);
		M[X] = ((2 * FDown + FUp) * FUp) % Mod;
	}
	else
	{
		FUp = F((X + 1) / 2);
		FDown = F((X + 1) / 2 - 1);
		M[X] = (FUp * FUp + FDown * FDown) % Mod;
	}

	return M[X];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll N;
	cin >> N;
	cout << F(N);
}