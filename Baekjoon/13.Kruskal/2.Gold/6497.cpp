#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
	int Cost;
	int A;
	int B;

	bool operator<(const Edge& Other) const
	{
		return Cost < Other.Cost;
	}
};

const int MaxNum = 200000;

int M, N, R[MaxNum];
Edge E[MaxNum];

int Find(int A)
{
	if (R[A] == A)
	{
		return A;
	}

	return R[A] = Find(R[A]);
}

void Union(int A, int B)
{
	R[Find(B)] = Find(A);
}

bool Test()
{
	cin >> M >> N;
	if (M == 0 && N == 0)
	{
		return false;
	}

	for (int i = 0; i < M; ++i)
	{
		R[i] = i;
	}

	int SumCost = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> E[i].A >> E[i].B >> E[i].Cost;
		SumCost += E[i].Cost;
	}

	sort(E, E + N);

	int Count = 0;
	for (int i = 0; i < N; ++i)
	{
		if (Find(E[i].A) == Find(E[i].B))
		{
			continue;
		}

		Union(E[i].A, E[i].B);
		SumCost -= E[i].Cost;
		if (++Count == M - 1)
		{
			break;
		}
	}

	cout << SumCost << '\n';

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (Test()) {}
}