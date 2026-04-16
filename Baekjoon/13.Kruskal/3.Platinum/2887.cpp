#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

using p = pair<int, int>;

struct Edge
{
	int D;
	int A;
	int B;

	bool operator<(const Edge& Other) const
	{
		return D < Other.D;
	}
};

const int MaxN = 100000;

int N, R[MaxN];
p PX[MaxN], PY[MaxN], PZ[MaxN];

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

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> PX[i].first >> PY[i].first >> PZ[i].first;
		PX[i].second = i;
		PY[i].second = i;
		PZ[i].second = i;
		R[i] = i;
	}

	sort(PX, PX + N);
	sort(PY, PY + N);
	sort(PZ, PZ + N);

	vector<Edge> E;
	for (int i = 0; i < N - 1; ++i)
	{
		E.emplace_back(Edge{ abs(PX[i + 1].first - PX[i].first), PX[i].second, PX[i + 1].second });
		E.emplace_back(Edge{ abs(PY[i + 1].first - PY[i].first), PY[i].second, PY[i + 1].second });
		E.emplace_back(Edge{ abs(PZ[i + 1].first - PZ[i].first), PZ[i].second, PZ[i + 1].second });
	}

	sort(E.begin(), E.end());

	int Count = 0;
	long long Sum = 0;
	for (const Edge& edge : E)
	{
		if (Find(edge.A) == Find(edge.B))
		{
			continue;
		}

		Sum += edge.D;
		Union(edge.A, edge.B);
		if (++Count == N - 1)
		{
			break;
		}
	}

	cout << Sum;
}