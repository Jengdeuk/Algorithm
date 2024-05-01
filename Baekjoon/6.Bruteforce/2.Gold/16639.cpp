#include <iostream>
#include <string>
#include <climits>
using namespace std;

int N;
string Formula;

int Idx[19], Val[19], Op[9];
bool Visited[19];
int Max = -INT_MAX - 1;

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
	for (int i = 0; i < N; ++i)
	{
		Idx[i] = i;
		Val[i] = Formula[i] - '0';
	}

	for (int i = 0; i < N / 2; ++i)
	{
		int M = Op[i];
		int L = Find(M - 1);
		int R = Find(M + 1);
		switch (Formula[M])
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

	return Val[0];
}

void DFS(int Cur)
{
	if (Cur == N / 2)
	{
		Max = max(Max, Calculate());
		return;
	}

	for (int i = 1; i < N; i += 2)
	{
		if (Visited[i])
		{
			continue;
		}

		Visited[i] = true;
		Op[Cur] = i;
		DFS(Cur + 1);
		Visited[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> Formula;
	DFS(0);
	cout << Max;
}