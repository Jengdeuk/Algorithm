#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

typedef pair<int, int> p;

int N;
p P[16];
double DP[16][(1 << 16)];

double GetDistance(const int& Src, const int& Dst)
{
	return sqrt(pow(double(P[Dst].first - P[Src].first), 2) + pow(double(P[Dst].second - P[Src].second), 2));
}

bool IsFinished(int Bit)
{
	for (int i = 0; i < N; ++i)
	{
		if ((Bit & (1 << i)) == false)
		{
			return false;
		}
	}

	return true;
}

double GoNextCity(int Cur, int Bit)
{
	if (Bit == (1 << N) - 1)
	{
		return GetDistance(Cur, 0);
	}

	if (DP[Cur][Bit])
	{
		return DP[Cur][Bit];
	}

	DP[Cur][Bit] = 1234567890;
	for (int i = 0; i < N; ++i)
	{
		if (Bit & (1 << i))
		{
			continue;
		}
		
		DP[Cur][Bit] = min(DP[Cur][Bit], GetDistance(Cur, i) + GoNextCity(i, Bit | (1 << i)));
	}

	return DP[Cur][Bit];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> P[i].first >> P[i].second;
	}

	cout << fixed;
	cout << GoNextCity(0, (1 << 0));
}