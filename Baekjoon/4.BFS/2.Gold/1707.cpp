#include <iostream>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> p;

list<int> N[20001];
int Color[20001];

bool BFS(int Start)
{
	queue<p> Q;
	Q.emplace(Start, 0);
	Color[Start] = 0;
	while (!Q.empty())
	{
		int Cur = Q.front().first;
		int Col = Q.front().second;
		Q.pop();

		int NCol = (Col == 1 ? 0 : 1);
		for (const int& n : N[Cur])
		{
			if (Color[n] == -1)
			{
				Q.emplace(n, NCol);
				Color[n] = NCol;
				continue;
			}

			if (Color[n] == Col)
			{
				return false;
			}
		}
	}

	return true;
}

void Test()
{
	int V, E;
	cin >> V >> E;
	for (int i = 1; i <= V; ++i)
	{
		N[i].clear();
		Color[i] = -1;
	}

	for (int i = 0; i < E; ++i)
	{
		int A, B;
		cin >> A >> B;
		N[A].emplace_back(B);
		N[B].emplace_back(A);
	}

	for (int i = 1; i <= V; ++i)
	{
		if (Color[i] == -1)
		{
			if (BFS(i) == false)
			{
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int K;
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		Test();
	}
}