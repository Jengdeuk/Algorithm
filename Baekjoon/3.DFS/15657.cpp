#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int N, M;
vector<int> Numbers;

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

	for (int i = Number; i < N; ++i)
	{
		Sequence[Index] = Numbers[i];
		DFS(Sequence, Index + 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	Numbers.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Number;
		cin >> Number;
		Numbers.emplace_back(Number);
	}

	sort(Numbers.begin(), Numbers.end());

	int Sequence[8];
	DFS(Sequence, 0, 0);
}