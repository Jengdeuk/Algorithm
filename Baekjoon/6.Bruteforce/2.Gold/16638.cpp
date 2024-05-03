#include <iostream>
#include <string>
#include <climits>
#include <cstring>
using namespace std;

int N;
string Formula;

int Idx[19], Val[19];
bool BrOp[9], Visited[9];
int Max = INT_MIN;

int Find(int Node)
{
	if (Node == Idx[Node])
	{
		return Node;
	}

	return Idx[Node] = Find(Idx[Node]);
}

void Union(int NodeA, int NodeB)
{
	int A = Find(NodeA);
	int B = Find(NodeB);
	int Min = min(A, B);
	Idx[A] = Min;
	Idx[B] = Min;
}

int Calculate()
{
	memset(Visited, false, sizeof(Visited));

	for (int i = 0; i < N; ++i)
	{
		Idx[i] = i;
		Val[i] = Formula[i] - '0';
	}

	for (int i = 0, j = 1; i < N / 2 && j < N; ++i, j += 2)
	{
		if (!BrOp[i] || Visited[i])
		{
			continue;
		}

		Visited[i] = true;
		int L = Find(j - 1);
		int R = Find(j + 1);
		switch (Formula[j])
		{
		case '+':
			Val[L] = Val[L] + Val[R];
			break;
		case '-':
			Val[L] = Val[L] - Val[R];
			break;
		case '*':
			Val[L] = Val[L] * Val[R];
			break;
		}
		Union(L, R);
	}

	for (int i = 0, j = 1; i < N / 2 && j < N; ++i, j += 2)
	{
		if (Formula[j] != '*' || Visited[i])
		{
			continue;
		}

		int L = Find(j - 1);
		int R = Find(j + 1);
		Val[L] = Val[L] * Val[R];
		Union(L, R);
	}

	for (int i = 0, j = 1; i < N / 2 && j < N; ++i, j += 2)
	{
		if (Visited[i])
		{
			continue;
		}

		int L = Find(j - 1);
		int R = Find(j + 1);
		switch (Formula[j])
		{
		case '+':
			Val[L] = Val[L] + Val[R];
			break;
		case '-':
			Val[L] = Val[L] - Val[R];
			break;
		}
		Union(L, R);
	}

	return Val[0];
}

void DFS(int Cur)
{
	if (Cur == N / 2)
	{
		Max = max(Max, Calculate());
		return;
	}

	if (Cur == 0 || !BrOp[Cur - 1])
	{
		BrOp[Cur] = true;
		DFS(Cur + 1);
	}

	BrOp[Cur] = false;
	DFS(Cur + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> Formula;
	DFS(0);
	cout << Max;
}