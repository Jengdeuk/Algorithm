#include <iostream>
using namespace std;

int N, M;

void DFS(int Sequence[], int Index, int Number)
{
	if (Index == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << Sequence[i] << ' ';
		}
		cout << '\n';
		return;
	}

	Sequence[Index] = Number;
	if (Number <= N)
	{
		DFS(Sequence, Index + 1, Number + 1);
		DFS(Sequence, Index, Number + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int Sequence[8];
	DFS(Sequence, 0, 1);
}