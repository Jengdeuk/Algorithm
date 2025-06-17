#include <iostream>
#include <list>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int N;
list<int> F[501];
bool V[501];

int BFS()
{
	int Cnt = 0;
	queue<p> Q;
	V[1] = true;
	Q.emplace(0, 1);
	while (Q.empty() == false)
	{
		int Step = Q.front().first;
		int Cur = Q.front().second;
		Q.pop();

		Cnt++;
		if (Step == 2)
		{
			continue;
		}

		for (const int Nxt : F[Cur])
		{
			if (V[Nxt] == false)
			{
				V[Nxt] = true;
				Q.emplace(Step + 1, Nxt);
			}
		}
	}

	return Cnt - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	int M;
	cin >> M;
	while (M--)
	{
		int A, B;
		cin >> A >> B;
		F[A].emplace_back(B);
		F[B].emplace_back(A);
	}

	cout << BFS();
}