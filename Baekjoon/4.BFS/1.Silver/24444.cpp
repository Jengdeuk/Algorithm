#include <iostream>
#include <queue>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> pq;

int N, S[100001];
pq FQ[100001];
bool V[100001];

void BFS(int R)
{
	int Idx = 1;
	
	queue<int> Q;
	V[R] = true;
	Q.emplace(R);
	while (Q.empty() == false)
	{
		int Cur = Q.front();
		Q.pop();

		S[Cur] = Idx++;
		while (FQ[Cur].empty() == false)
		{
			int Nxt = FQ[Cur].top();
			FQ[Cur].pop();
			if (V[Nxt] == false)
			{
				V[Nxt] = true;
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
		FQ[A].emplace(B);
		FQ[B].emplace(A);
	}

	BFS(R);

	for (int i = 1; i <= N; ++i)
	{
		cout << S[i] << '\n';
	}
}