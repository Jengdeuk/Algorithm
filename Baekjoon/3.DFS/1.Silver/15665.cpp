#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Seq[7];
int Sel[7];
int Pre[7];

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

	return false;
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

void Backtracking(int Idx)
{
	if (Idx == M)
	{
		if (!Duplicate() && !Less())
		{
			Render();
		}

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