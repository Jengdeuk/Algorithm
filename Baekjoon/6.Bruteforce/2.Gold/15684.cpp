#include <iostream>
using namespace std;

int N, M, H;
bool Line[11][31];

int Min = 4;

bool Check()
{
	for (int i = 1; i <= N; ++i)
	{
		int n = i, h = 1;
		while (h <= H)
		{
			if (Line[n - 1][h])
			{
				--n;
			}
			else if (Line[n][h])
			{
				++n;
			}

			++h;
		}
		
		if (n != i)
		{
			return false;
		}
	}

	return true;
}

void Backtracking(int Cnt, int CurH)
{
	if (Cnt == 4)
	{
		return;
	}
	else if (Check())
	{
		Min = min(Min, Cnt);
		return;
	}

	for (int j = CurH; j <= H; ++j)
	{
		for (int i = 1; i < N; ++i)
		{
			if (Line[i - 1][j] || Line[i][j] || Line[i + 1][j]) continue;

			Line[i][j] = true;
			Backtracking(Cnt + 1, j);
			Line[i][j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> H;
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		Line[B][A] = true;
	}

	Backtracking(0, 1);

	if (Min < 4)
	{
		cout << Min;
	}
	else
	{
		cout << -1;
	}
}