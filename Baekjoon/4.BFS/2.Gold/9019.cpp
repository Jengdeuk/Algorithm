#include <iostream>
#include <string>
#include <queue>
using namespace std;

string Command[10000];
bool Visited[10000];
queue<int> SearchQueue;

void InitContainers()
{
	for (int i = 0; i < 10000; ++i)
	{
		Command[i] = "";
		Visited[i] = false;
	}

	while (!SearchQueue.empty())
	{
		SearchQueue.pop();
	}
}

bool FindTarget(int N, int Target)
{
	int D = 2 * N % 10000;
	if (!Visited[D] && Command[D] == "")
	{
		Command[D] = Command[N] + 'D';
		SearchQueue.emplace(D);

		if (D == Target)
		{
			cout << Command[D] << '\n';
			return true;
		}
	}

	int S = (N - 1 < 0) ? 9999 : N - 1;
	if (!Visited[S] && Command[S] == "")
	{
		Command[S] = Command[N] + 'S';
		SearchQueue.emplace(S);

		if (S == Target)
		{
			cout << Command[S] << '\n';
			return true;
		}
	}

	int L = (N % 1000) * 10 + (N / 1000);
	if (!Visited[L] && Command[L] == "")
	{
		Command[L] = Command[N] + 'L';
		SearchQueue.emplace(L);

		if (L == Target)
		{
			cout << Command[L] << '\n';
			return true;
		}
	}

	int R = (N % 10) * 1000 + N / 10;
	if (!Visited[R] && Command[R] == "")
	{
		Command[R] = Command[N] + 'R';
		SearchQueue.emplace(R);

		if (R == Target)
		{
			cout << Command[R] << '\n';
			return true;
		}
	}

	return false;
}

void DFS(int Start, int Target)
{
	SearchQueue.emplace(Start);

	while (!SearchQueue.empty())
	{
		int N = SearchQueue.front();
		SearchQueue.pop();
		if (Visited[N])
		{
			continue;
		}

		Visited[N] = true;
		if (FindTarget(N, Target))
		{
			break;
		}
	}
}

void Test()
{
	InitContainers();

	int Start, Target;
	cin >> Start >> Target;

	DFS(Start, Target);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}