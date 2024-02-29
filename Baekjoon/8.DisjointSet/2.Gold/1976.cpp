#include <iostream>
#include <vector>
using namespace std;

vector<int> RootNode;
vector<int> Schedule;

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

	RootNode.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		RootNode.emplace_back(i);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int bLinked;
			cin >> bLinked;

			if (j < i + 1)
			{
				continue;
			}

			if (bLinked == 1)
			{
				Union(i, j);
			}
		}
	}

	Schedule.reserve(M);
	for (int i = 0; i < M; ++i)
	{
		int City;
		cin >> City;
		Schedule.emplace_back(City - 1);
	}

	int Index = 0;
	for (const int& City : Schedule)
	{
		if (Index == Schedule.size() - 1)
		{
			break;
		}

		int NextCity = Schedule[Index + 1];
		if (!Determine(City, NextCity))
		{
			cout << "NO";
			return 0;
		}

		++Index;
	}

	cout << "YES";
}