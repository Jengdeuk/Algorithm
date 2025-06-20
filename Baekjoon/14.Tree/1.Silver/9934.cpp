#include <iostream>
#include <list>
using namespace std;

int K, N, S[1 << 10];
list<int> L[11];

void InitTree(int Level, int Start, int End)
{
	if (Level == K + 1)
	{
		return;
	}

	int Idx = (Start + End) >> 1;
	L[Level].emplace_back(S[Idx]);
	InitTree(Level + 1, Start, Idx - 1);
	InitTree(Level + 1, Idx + 1, End);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> K;
	N = (1 << K) - 1;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	InitTree(1, 0, N - 1);

	for (int i = 1; i <= K; ++i)
	{
		for (const int Num : L[i])
		{
			cout << Num << ' ';
		}
		cout << '\n';
	}
}