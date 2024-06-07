#include <iostream>
#include <list>
using namespace std;

int N, R, Q;
list<int> Neighbor[100001];
list<int> Child[100001];
bool Visited[100001];
int Size[100001];

void DFS(int Cur)
{
	Visited[Cur] = true;

	for (const int& Ngb : Neighbor[Cur])
	{
		if (!Visited[Ngb])
		{
			Child[Cur].emplace_back(Ngb);
		}
	}

	for (const int& Chd : Child[Cur])
	{
		DFS(Chd);
	}
}

int Fill(int Cur)
{
	int S = 1;
	for (const int& Chd : Child[Cur])
	{
		S += Fill(Chd);
	}

	return Size[Cur] = S;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; ++i)
	{
		int U, V;
		cin >> U >> V;
		Neighbor[U].emplace_back(V);
		Neighbor[V].emplace_back(U);
	}

	DFS(R);
	Fill(R);

	for (int i = 0; i < Q; ++i)
	{
		int U;
		cin >> U;
		cout << Size[U] << '\n';
	}
}