#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int N, Root, Cnt;
int P[50];
list<int> C[50];

void DFS(int Node)
{
	if (C[Node].empty())
	{
		++Cnt;
		return;
	}

	for (const int& Child : C[Node])
	{
		DFS(Child);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Parent;
		cin >> Parent;
		P[i] = Parent;

		if (Parent == -1)
		{
			Root = i;
			continue;
		}

		C[Parent].emplace_back(i);
	}

	int D;
	cin >> D;
	if (D == Root)
	{
		cout << 0;
		return 0;
	}

	C[P[D]].erase(find(C[P[D]].begin(), C[P[D]].end(), D));

	DFS(Root);
	cout << Cnt;
}