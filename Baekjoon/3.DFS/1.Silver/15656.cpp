#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Seq[7];
int Sel[7];

void Backtracking(int Idx)
{
	if (Idx == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << Sel[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < N; ++i)
	{
		Sel[Idx] = Seq[i];
		Backtracking(Idx + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> Seq[i];
	}

	sort(Seq, Seq + N);

	Backtracking(0);
}