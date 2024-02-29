#include <iostream>
#include <list>
#include <queue>
using namespace std;

const int& MaxSize = 10001;

list<int> Children[MaxSize];
pair<int, int> Tree[MaxSize];
queue<int> SearchQueue;

void SearchLCA(int NodeA, int NodeB)
{
	int A = NodeA;
	int B = NodeB;

	while (Tree[A].second != Tree[B].second)
	{
		if (Tree[A].second > Tree[B].second)
		{
			A = Tree[A].first;
		}
		else if (Tree[A].second < Tree[B].second)
		{
			B = Tree[B].first;
		}
	}

	if (A == B)
	{
		cout << A << '\n';
		return;
	}

	while (A != B)
	{
		A = Tree[A].first;
		B = Tree[B].first;
	}

	cout << A << '\n';
}

void InitDepthInfo(int RootNode)
{
	Tree[RootNode].second = 1;

	SearchQueue.emplace(RootNode);
	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.front();
		SearchQueue.pop();

		for (const int& Child : Children[Current])
		{
			Tree[Child].second = Tree[Current].second + 1;
			SearchQueue.emplace(Child);
		}
	}
}

void TestCase()
{
	for (int i = 0; i < MaxSize; ++i)
	{
		Children[i].clear();
		Tree[i] = pair<int, int>();
	}

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; ++i)
	{
		int A, B;
		cin >> A >> B;
		Children[A].emplace_back(B);
		Tree[B].first = A;
	}

	int RootNode = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (Tree[i].first == 0)
		{
			RootNode = i;
		}
	}

	InitDepthInfo(RootNode);

	int NodeA, NodeB;
	cin >> NodeA >> NodeB;

	SearchLCA(NodeA, NodeB);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		TestCase();
	}
}