#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef pair<int, int> p;

int N, M;
char EL[50][50];
int Root[50], Road[50];

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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		Root[i] = i;
	}

	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;

		for (int j = 0; j < N; ++j)
		{
			EL[i][j] = S[j];
		}
	}

	int Count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (Count < N - 1 && EL[i][j] == 'Y' && Find(i) != Find(j))
			{
				EL[i][j] = 'N';
				Union(i, j);
				++Road[i];
				++Road[j];
				++Count;
				if (Count == N - 1)
				{
					i = N, j = N;
					break;
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if (Find(i) != 0)
		{
			cout << -1;
			return 0;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (Count < M && EL[i][j] == 'Y')
			{
				++Road[i];
				++Road[j];
				++Count;
			}
		}
	}

	if (Count == M)
	{
		for (int i = 0; i < N; ++i)
		{
			cout << Road[i] << ' ';
		}
	}
	else
	{
		cout << -1;
	}
}