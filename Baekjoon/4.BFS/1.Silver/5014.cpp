#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int F, S, G, U, D;
bool V[1000001];

int BFS()
{
	queue<p> Q;
	V[S] = true;
	Q.emplace(S, 0);
	while (!Q.empty())
	{
		int Cur = Q.front().first;
		int Btn = Q.front().second;
		Q.pop();

		if (Cur == G)
		{
			return Btn;
		}

		if (Cur + U <= F && V[Cur + U] == false)
		{
			V[Cur + U] = true;
			Q.emplace(Cur + U, Btn + 1);
		}

		if (Cur - D >= 1 && V[Cur - D] == false)
		{
			V[Cur - D] = true;
			Q.emplace(Cur - D, Btn + 1);
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> F >> S >> G >> U >> D;

	int Cnt = BFS();
	if (Cnt >= 0)
	{
		cout << Cnt;
	}
	else
	{
		cout << "use the stairs";
	}
}