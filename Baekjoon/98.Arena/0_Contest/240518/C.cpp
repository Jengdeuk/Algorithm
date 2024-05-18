#include <iostream>
using namespace std;

int N, M, Cnt;
int Sol[1000];

void DFS(int Idx)
{
	if (Idx == M)
	{
		++Cnt;
		Cnt %= 1000000007;
		return;
	}

	for (int i = 1; i <= 26; ++i)
	{
		if (Idx > 0 && abs(Sol[Idx - 1] - i) < N)
		{
			continue;
		}

		Sol[Idx] = i;
		DFS(Idx + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	DFS(0);
	cout << Cnt;
}