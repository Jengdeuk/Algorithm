#include <iostream>
#include <cmath>
#include <list>
#include <queue>
using namespace std;

const int& MaxSize = 100001;
const int& MaxK = 20;
int K;
int MaxDepth;

list<int> Neighbors[MaxSize];
int Depth[MaxSize];
int Parent[MaxK][MaxSize];
queue<int> SearchQueue;
bool Visited[MaxSize];

void SearchLCA(int NodeA, int NodeB)
{
	int A = NodeA;
	int B = NodeB;

	if (Depth[A] != Depth[B])
	{
		if (Depth[A] > Depth[B])
		{
			int Temp = A;
			A = B;
			B = Temp;
		}

		int Gap = Depth[B] - Depth[A];
		for (int i = 0; Gap > 0; ++i)
		{
			if (Gap % 2 == 1)
			{
				B = Parent[i][B];
			}

			Gap = Gap >> 1;
		}
	}

	if (A == B)
	{
		cout << A << '\n';
		return;
	}

	int S = K;
	while (S >= 0)
	{
		if (Parent[S][A] != Parent[S][B]
			&& Parent[S][A] != 0
			&& Parent[S][B] != 0)
		{
			A = Parent[S][A];
			B = Parent[S][B];
		}

		--S;
	}

	if (A != B)
	{
		A = Parent[0][A];
		B = Parent[0][B];
	}

	cout << A << '\n';
}

void DP(int N)
{
	while (true)
	{
		if (pow(2, K) >= MaxDepth)
		{
			--K;
			break;
		}

		++K;
	}

	for (int i = 1; i <= K; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (Parent[i - 1][Parent[i - 1][j]] == 0)
			{
				continue;
			}

			Parent[i][j] = Parent[i - 1][Parent[i - 1][j]];
		}
	}
}

void InitTree(int RootNode)
{
	Depth[RootNode] = 1;
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

			Depth[Child] = Depth[Current] + 1;
			MaxDepth = max(MaxDepth, Depth[Child]);
			Parent[0][Child] = Current;
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
	DP(N);

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		SearchLCA(A, B);
	}
}