#include <iostream>
using namespace std;

typedef pair<int, int> team;

int N, M, K;
int Candy[30000];
int Root[30000];
bool Visited[30000];

int TeamNum;
team Team[30000];
int DP[30001][3001];

int Find(int Node)
{
	if (Node == Root[Node])
	{
		return Node;
	}

	return Root[Node] = Find(Root[Node]);
}

void Union(int NodeA, int NodeB)
{
	int A = Find(NodeA);
	int B = Find(NodeB);

	int Min = min(A, B);
	Root[A] = Min;
	Root[B] = Min;
}

void InitTeam()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; ++i)
	{
		cin >> Candy[i];
		Root[i] = i;
	}

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		Union(A - 1, B - 1);
	}

	for (int i = 0; i < N; ++i)
	{
		if (Visited[i])
		{
			continue;
		}

		int R = Find(i);
		Visited[i] = true;
		++Team[TeamNum].first;
		Team[TeamNum].second += Candy[i];
		for (int j = i + 1; j < N; ++j)
		{
			if (R == Find(j))
			{
				Visited[j] = true;
				++Team[TeamNum].first;
				Team[TeamNum].second += Candy[j];
			}
		}

		++TeamNum;
	}
}

int DynamicProgramming()
{
	for (int i = 1; i <= TeamNum; ++i)
	{
		int Num = Team[i - 1].first;
		int Cdy = Team[i - 1].second;

		for (int n = 0; n < K; ++n)
		{
			if (Num <= n)
			{
				DP[i][n] = max(DP[i - 1][n], DP[i - 1][n - Num] + Cdy);
			}
			else
			{
				DP[i][n] = DP[i - 1][n];
			}
		}
	}

	return DP[TeamNum][K - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	InitTeam();
	cout << DynamicProgramming();
}