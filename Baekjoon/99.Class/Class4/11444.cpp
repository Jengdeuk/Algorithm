#include <iostream>
#include <map>
using namespace std;

const int Mod = 1000000007;
map<long long, long long> FivonacciMap;

long long Fivonacci(long long Num)
{
	if (Num == 0)
	{
		return 0;
	}
	else if (Num == 1 || Num == 2)
	{
		return 1;
	}
	else if (FivonacciMap.count(Num) > 0)
	{
		return FivonacciMap[Num];
	}

	long long FUp, FDown;
	if (Num % 2 == 0)
	{
		FUp = Fivonacci(Num / 2);
		FDown = Fivonacci(Num / 2 - 1);
		FivonacciMap[Num] = ((2 * FDown + FUp) * FUp) % Mod;
	}
	else
	{
		FUp = Fivonacci((Num + 1) / 2);
		FDown = Fivonacci((Num + 1) / 2 - 1);
		FivonacciMap[Num] = (FUp * FUp + FDown * FDown) % Mod;
	}

	return FivonacciMap[Num];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	long long N;
	cin >> N;
	cout << Fivonacci(N);
}