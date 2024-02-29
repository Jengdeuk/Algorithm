#include <iostream>
#include <vector>
using namespace std;

vector<int> RootNode;

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
	int RootNodeA = Find(NodeA);
	int RootNodeB = Find(NodeB);

	int MinRootNode = min(RootNodeA, RootNodeB);
	RootNode[RootNodeA] = MinRootNode;
	RootNode[RootNodeB] = MinRootNode;
}

bool Determine(int NodeA, int NodeB)
{
	return (Find(NodeA) == Find(NodeB));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	RootNode.reserve(N + 1);
	for (int i = 0; i < N + 1; ++i)
	{
		RootNode.emplace_back(i);
	}

	for (int i = 0; i < M; ++i)
	{
		int Option, A, B;
		cin >> Option >> A >> B;

		if (Option == 0)
		{
			Union(A, B);
			continue;
		}

		if (Determine(A, B))
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}
}