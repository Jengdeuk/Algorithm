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

const int MaxNode = 100000;
const int MaxEdge = 1000000;

int N, M, R[MaxNode + 1];
Edge E[MaxEdge];

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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		R[i] = i;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> E[i].A >> E[i].B >> E[i].Cost;
	}

	sort(E, E + M);

	int Count = 0;
	int Sum = 0;
	for (int i = 0; i < M; ++i)
	{
		if (Find(E[i].A) == Find(E[i].B))
		{
			continue;
		}

		Sum += E[i].Cost;
		Union(E[i].A, E[i].B);
		if (++Count == N - 2)
		{
			break;
		}
	}

	if (N == 2)
	{
		cout << 0;
	}
	else
	{
		cout << Sum;
	}
}