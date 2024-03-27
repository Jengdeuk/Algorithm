#include <iostream>
#include <list>
#include <queue>
using namespace std;

list<int> Neighbor[101];
bool Visited[101];

int BFS(int S, int E)
{
	queue<pair<int, int>> SQ;
	Visited[S] = true;
	SQ.emplace(S, 0);
	while (!SQ.empty())
	{
		int C = SQ.front().first;
		int D = SQ.front().second;
		SQ.pop();

		if (C == E)
		{
			return D;
		}

		for (const int& N : Neighbor[C])
		{
			if (!Visited[N])
			{
				Visited[N] = true;
				SQ.emplace(N, D + 1);
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	
	int S, E;
	cin >> S >> E;

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		Neighbor[A].emplace_back(B);
		Neighbor[B].emplace_back(A);
	}

	cout << BFS(S, E);
}