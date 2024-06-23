#include <iostream>
#include <list>
#include <cstring>
using namespace std;

int N, M;
list<int> F[2000];

bool bFind;
bool V[2000];

void DFS(int Current, int Depth)
{
	if (Depth == 5)
	{
		bFind = true;
		return;
	}

	for (const int f : F[Current])
	{
		if (!V[f])
		{
			V[f] = true;
			DFS(f, Depth + 1);
			V[f] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		F[A].emplace_back(B);
		F[B].emplace_back(A);
	}

	for (int i = 0; i < N; ++i)
	{
		memset(V, false, sizeof(V));
		V[i] = true;
		DFS(i, 1);

		if (bFind)
		{
			break;
		}
	}

	cout << bFind;
}