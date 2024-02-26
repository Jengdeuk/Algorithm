#include <iostream>
using namespace std;

int Root[500000];

int Find(int Node)
{
	if (Node == Root[Node])
	{
		return Node;
	}

	return Root[Node] = Find(Root[Node]);
}

bool Cycle(int NodeA, int NodeB)
{
	int RootA = Find(NodeA);
	int RootB = Find(NodeB);

	if (RootA == RootB)
	{
		return true;
	}

	// Union
	int NewRoot = min(RootA, RootB);
	Root[RootA] = NewRoot;
	Root[RootB] = NewRoot;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		Root[i] = i;
	}

	bool bFound = false;
	int Cnt = 0;
	for (int i = 1; i <= M; ++i)
	{
		int A, B;
		cin >> A >> B;

		if (!bFound && Cycle(A, B))
		{
			bFound = true;
			Cnt = i;
		}
	}

	cout << Cnt;
}