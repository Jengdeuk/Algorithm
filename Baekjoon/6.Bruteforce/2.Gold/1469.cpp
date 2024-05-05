#include <iostream>
#include <algorithm>
using namespace std;

int N, X[8], S[16], Num[8];

void DFS(int Idx);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> X[i];
	}

	sort(X, X + N);

	DFS(0);

	cout << -1;
}

void DFS(int Idx)
{
	if (Idx == 2 * N)
	{
		for (int i = 0; i < 2 * N; ++i)
		{
			cout << S[i] << ' ';
		}

		exit(0);
	}

	for (int i = 0; i < N; ++i)
	{
		if (Num[i] == 2
			|| (Num[i] == 1 && (Idx - X[i] - 1 < 0 || S[Idx - X[i] - 1] != X[i])))
		{
			continue;
		}

		S[Idx] = X[i];
		++Num[i];
		DFS(Idx + 1);
		--Num[i];
	}
}