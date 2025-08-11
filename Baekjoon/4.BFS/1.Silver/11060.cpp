#include <iostream>
#include <queue>
using namespace std;

int N, M[1000], V[1000];

int BFS()
{
	queue<int> Q;
	Q.emplace(0);
	while (Q.empty() == false)
	{
		int Cur = Q.front();
		Q.pop();

		if (Cur == N - 1)
		{
			return V[Cur];
		}

		for (int i = 1; i <= M[Cur]; ++i)
		{
			int Nxt = Cur + i;
			if (V[Nxt] == 0)
			{
				V[Nxt] = V[Cur] + 1;
				Q.emplace(Nxt);
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> M[i];
	}

	cout << BFS();
}