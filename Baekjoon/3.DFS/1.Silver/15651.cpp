#include <iostream>
using namespace std;

int N, M;
int Sequence[7];

void DFS(int Index)
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

	for (int i = 1; i <= N; ++i)
	{
		Sequence[Index] = i;
		DFS(Index + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	DFS(0);
}