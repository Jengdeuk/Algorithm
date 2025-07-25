#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

const int MS = 40000;

bool P[MS + 1];
vector<int> PN;
map<int, int> PF;

void InitPrime()
{
	for (int i = 2; i <= MS; ++i)
		P[i] = true;

	for (int i = 2; i <= sqrt(MS); ++i)
	{
		if (P[i] == false)
			continue;

		for (int j = i * i; j <= MS; j += i)
			P[j] = false;
	}

	for (int i = 2; i <= MS; ++i)
	{
		if (P[i])
		{
			PN.emplace_back(i);
		}
	}
}

void MakePF(int X)
{
	if (X == 1)
	{
		return;
	}

	for (const int PrimeNumber : PN)
	{
		if (PrimeNumber > X)
		{
			break;
		}

		while (X % PrimeNumber == 0)
		{
			X /= PrimeNumber;
			PF[PrimeNumber]++;
		}
	}

	if (X > 1)
	{
		PF[X]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	InitPrime();

	while (true)
	{
		int N;
		cin >> N;
		if (N == 0)
		{
			break;
		}
		else if (N == 1)
		{
			cout << 0 << '\n';
			continue;
		}

		map<int, int>().swap(PF);
		MakePF(N);

		int Answer = 1;
		for (pair<int, int> PrimeFactor : PF)
		{
			Answer *= pow(PrimeFactor.first, PrimeFactor.second - 1) * (PrimeFactor.first - 1);
		}

		cout << Answer << '\n';
	}
}