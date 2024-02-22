#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<tuple<int, int, int>> Edges;
int RootNode[100000];

int Find(int Node)
{
	if (Node == RootNode[Node])
	{
		return Node;
	}

	return RootNode[Node] = Find(RootNode[Node]);
}

void Union(int NodeA, int NodeB)
{
	int A = Find(NodeA);
	int B = Find(NodeB);

	int Min = min(A, B);
	RootNode[A] = Min;
	RootNode[B] = Min;
}

int Kruskal(int N, int M)
{
	if (N == 2)
	{
		return 0;
	}

	int Cost = 0;
	int Linked = 0;
	for (int i = 0; i < M; ++i)
	{
		int NodeA = get<1>(Edges[i]);
		int NodeB = get<2>(Edges[i]);
		if (Find(NodeA) != Find(NodeB))
		{
			Union(NodeA, NodeB);
			Cost += get<0>(Edges[i]);
			++Linked;

			if (Linked == N - 2)
			{
				break;
			}
		}
	}

	return Cost;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		RootNode[i] = i;
	}

	Edges.reserve(M);
	for (int i = 0; i < M; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		Edges.emplace_back(C, A - 1, B - 1);
	}

	sort(Edges.begin(), Edges.end());

	cout << Kruskal(N, M);
}