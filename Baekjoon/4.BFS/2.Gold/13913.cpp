#include <iostream>
#include <queue>
#include <deque>
using namespace std;

typedef pair<int, int> p;

int N, K;
int P[200001];
bool V[200001];
queue<p> Q;
deque<int> R;

bool IsValid(int X)
{
	return (X >= 0 && X <= 200000 && !V[X]);
}

void Move(int T, int Cur, int Nxt)
{
	if (IsValid(Nxt))
	{
		P[Nxt] = Cur;
		V[Nxt] = true;
		Q.emplace(T + 1, Nxt);
	}
}

int BFS()
{
	P[N] = -1;
	V[N] = true;
	Q.emplace(0, N);
	while (!Q.empty())
	{
		int T = Q.front().first;
		int Cur = Q.front().second;
		Q.pop();

		if (Cur == K)
		{
			return T;
		}

		Move(T, Cur, Cur - 1);
		Move(T, Cur, Cur + 1);
		Move(T, Cur, 2 * Cur);
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;

	cout << BFS() << '\n';

	R.emplace_front(K);

	int Nxt = P[K];
	while (Nxt != -1)
	{
		R.emplace_front(Nxt);
		Nxt = P[Nxt];
	}

	while (!R.empty())
	{
		cout << R.front() << ' ';
		R.pop_front();
	}
}