#include <iostream>
#include <list>
#include <queue>
using namespace std;

const int& MaxSize = 50001;

list<int> Neighbors[MaxSize];
pair<int, int> Tree[MaxSize];
queue<int> SearchQueue;
bool Visited[MaxSize];

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

void InitTree(int RootNode)
{
	Tree[RootNode].first = 0;
	Tree[RootNode].second = 1;

	SearchQueue.emplace(RootNode);
	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.front();
		SearchQueue.pop();

		if (Visited[Current])
		{
			continue;
		}

		Visited[Current] = true;
		for (const int& Child : Neighbors[Current])
		{
			if (Visited[Child])
			{
				continue;
			}

			Tree[Child].first = Current;
			Tree[Child].second = Tree[Current].second + 1;
			SearchQueue.emplace(Child);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; ++i)
	{
		int A, B;
		cin >> A >> B;
		Neighbors[A].emplace_back(B);
		Neighbors[B].emplace_back(A);
	}

	InitTree(1);

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		SearchLCA(A, B);
	}
}