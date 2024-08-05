#include <iostream>
using namespace std;

int N;
int S[8];
bool C[9];

void DFS(int Idx)
{
	if (Idx == N)
	{
		for (int i = 0; i < N; ++i)
		{
			cout << S[i] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; ++i)
	{
		if (C[i])
		{
			continue;
		}

		S[Idx] = i;
		C[i] = true;
		DFS(Idx + 1);
		C[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	DFS(0);
}