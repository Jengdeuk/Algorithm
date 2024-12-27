#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, C[10001];
vector<int> P[10001];

void BFS(int Start)
{
	int Cnt = 0;
	bool V[10001] = {};

	queue<int> Q;
	V[Start] = true;
	Q.emplace(Start);
	++Cnt;
	while (!Q.empty())
	{
		int Cur = Q.front();
		Q.pop();

		for (int Nxt : P[Cur])
		{
			if (!V[Nxt])
			{
				V[Nxt] = true;
				Q.emplace(Nxt);
				++Cnt;
			}
		}
	}

	C[Start] = Cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		P[B].emplace_back(A);
	}

	int Max = 0;
	for (int i = 1; i <= N; ++i)
	{
		BFS(i);
		Max = max(Max, C[i]);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (C[i] == Max)
		{
			cout << i << ' ';
		}
	}
}