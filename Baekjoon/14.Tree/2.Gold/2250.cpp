#include <iostream>
using namespace std;

int N, Idx, MLevel;
int Ch[10001][2], Pa[10001];
int Min[10001], Max[10001];

void DFS(int Level, int Node)
{
	MLevel = max(MLevel, Level);

	int Child = Ch[Node][0];
	if (Child != -1)
	{
		DFS(Level + 1, Child);
	}

	Min[Level] = min(Min[Level], Idx);
	Max[Level] = max(Max[Level], Idx);
	++Idx;

	Child = Ch[Node][1];
	if (Child != -1)
	{
		DFS(Level + 1, Child);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 1; i <= 10000; ++i)
	{
		Min[i] = 10001;
	}

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;

		Ch[A][0] = B;
		Ch[A][1] = C;
		Pa[B] = A;
		Pa[C] = A;
	}

	int Root = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (Pa[i] == 0)
		{
			Root = i;
			break;
		}
	}

	Idx = 1;
	DFS(1, Root);

	int Gap = -1;
	int Gi = 0;
	for (int i = 1; i <= MLevel; ++i)
	{
		int G = Max[i] - Min[i];
		if (G > Gap)
		{
			Gap = G;
			Gi = i;
		}
	}

	cout << Gi << ' ' << Gap + 1;
}