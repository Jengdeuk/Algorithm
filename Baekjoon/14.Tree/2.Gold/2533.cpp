#include <iostream>
#include <list>
using namespace std;

int N;
list<int> F[1000001];
int DP[1000001][2];
bool V[1000001];

void SearchTree(int Node)
{
	V[Node] = true;
	++DP[Node][1];

	for (const int& Friend : F[Node])
	{
		if (V[Friend])
		{
			continue;
		}

		SearchTree(Friend);
		DP[Node][0] += DP[Friend][1];
		DP[Node][1] += min(DP[Friend][0], DP[Friend][1]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; ++i)
	{
		int A, B;
		cin >> A >> B;
		F[A].emplace_back(B);
		F[B].emplace_back(A);
	}

	SearchTree(1);

	cout << min(DP[1][0], DP[1][1]);
}