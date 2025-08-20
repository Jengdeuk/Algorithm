#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, V[100001];
vector<int> F[100001];

void BFS(int StartNode)
{
	int Cnt = 0;

	queue<int> Q;
	V[StartNode] = ++Cnt;
	Q.emplace(StartNode);
	while (Q.empty() == false)
	{
		int Cur = Q.front();
		Q.pop();

		for (const int Nxt : F[Cur])
		{
			if (V[Nxt] == 0)
			{
				V[Nxt] = ++Cnt;
				Q.emplace(Nxt);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int M, R;
	cin >> N >> M >> R;
	while (M--)
	{
		int A, B;
		cin >> A >> B;
		F[A].emplace_back(B);
		F[B].emplace_back(A);
	}

	for (int i = 1; i <= N; ++i)
	{
		sort(F[i].begin(), F[i].end(), greater<>());
	}

	BFS(R);

	for (int i = 1; i <= N; ++i)
	{
		cout << V[i] << '\n';
	}
}