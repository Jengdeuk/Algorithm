#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Seq[8];
int Sel[8];
int Pre[8];

bool Duplicate()
{
	for (int i = 0; i < M; ++i)
	{
		if (Sel[i] != Pre[i])
		{
			return false;
		}
	}

	return true;
}

bool Less()
{
	for (int i = 0; i < M; ++i)
	{
		if (Sel[i] == Pre[i])
		{
			continue;
		}
		else if (Sel[i] < Pre[i])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Render()
{
	for (int i = 0; i < M; ++i)
	{
		cout << Sel[i] << ' ';
		Pre[i] = Sel[i];
	}
	cout << '\n';
}

void Backtracking(int Num, int Idx)
{
	if (Num == M)
	{
		if (!Duplicate() && !Less())
		{
			Render();
		}

		return;
	}

	if (Idx == N)
	{
		return;
	}

	Sel[Num] = Seq[Idx];
	Backtracking(Num + 1, Idx + 1);
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