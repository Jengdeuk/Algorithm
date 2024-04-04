#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Seq[8];
bool Sel[8];

void Backtracking(int Num, int Idx)
{
	if (Num == M)
	{
		for (int i = 0; i < N; ++i)
		{
			if (Sel[i])
			{
				cout << Seq[i] << ' ';
			}
		}
		cout << '\n';

		return;
	}

	if (Idx == N)
	{
		return;
	}

	Sel[Idx] = true;
	Backtracking(Num + 1, Idx + 1);
	Sel[Idx] = false;
	Backtracking(Num, Idx + 1);
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

	Backtracking(0, 0);
}