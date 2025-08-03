#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, V[100001];
vector<int> F[100001];
int Cur = 1;

void DFS(int Idx)
{
	V[Idx] = Cur++;

	for (const int Nxt : F[Idx])
	{
		if (V[Nxt] == 0)
		{
			DFS(Nxt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int M, R;
	cin >> N >> M >> R;
	while (M--)
	{
		int A, B;
		cin >> A >> B;
		F[A].emplace_back(B);
		F[B].emplace_back(A);
	}

	for (int i = 1; i <= N; ++i)
	{
		sort(F[i].begin(), F[i].end(), greater<>());
	}

	DFS(R);

	for (int i = 1; i <= N; ++i)
	{
		cout << V[i] << '\n';
	}
}