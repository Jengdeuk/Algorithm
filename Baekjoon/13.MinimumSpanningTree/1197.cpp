#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> EdgeList;
vector<int> RootNode;

bool Compare(const vector<int>& Left, const vector<int>& Right)
{
	return (Left[2] < Right[2]);
}

int Find(int Node)
{
	if (Node != RootNode[Node])
	{
		RootNode[Node] = Find(RootNode[Node]);
	}

	return RootNode[Node];
}

bool Union(int NodeA, int NodeB)
{
	int RootA = Find(NodeA);
	int RootB = Find(NodeB);

	if (RootA == RootB)
	{
		return false;
	}

	int MinRoot = min(RootA, RootB);
	RootNode[RootA] = MinRoot;
	RootNode[RootB] = MinRoot;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;

	EdgeList.reserve(E);
	for (int i = 0; i < E; ++i)
	{
		EdgeList.emplace_back(vector<int>(3, 0));

		int Start, End, Weight;
		cin >> Start >> End >> Weight;

		EdgeList.back()[0] = Start - 1;
		EdgeList.back()[1] = End - 1;
		EdgeList.back()[2] = Weight;
	}

	sort(EdgeList.begin(), EdgeList.end(), Compare);

	RootNode.reserve(V);
	for (int i = 0; i < V; ++i)
	{
		RootNode.emplace_back(i);
	}

	int Sum = 0;
	int Cnt = 0;
	int Current = 0;
	while (Cnt < V - 1)
	{
		int Start = EdgeList[Current][0];
		int End = EdgeList[Current][1];

		if (Union(Start, End))
		{
			int Weight = EdgeList[Current][2];
			Sum += Weight;
			++Cnt;
		}

		++Current;
	}

	cout << Sum;
}