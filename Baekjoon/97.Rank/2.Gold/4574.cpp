#include <iostream>
#include <cstring>
using namespace std;

const int DX[2] = { 1, 0 };
const int DY[2] = { 0, 1 };

bool bFinished, Used[10][10];
int Cur[9][9];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < 9 && C >= 0 && C < 9);
}

bool IsValidPut(int R, int C)
{
	for (int j = 0; j < 9; ++j)
	{
		if (j != C && Cur[R][j] == Cur[R][C])
		{
			return false;
		}
	}

	for (int i = 0; i < 9; ++i)
	{
		if (i != R && Cur[i][C] == Cur[R][C])
		{
			return false;
		}
	}

	int SR = (R / 3) * 3, SC = (C / 3) * 3;
	for (int i = SR; i < SR + 3; ++i)
	{
		for (int j = SC; j < SC + 3; ++j)
		{
			if (i != R && j != C && Cur[i][j] == Cur[R][C])
			{
				return false;
			}
		}
	}

	return true;
}

void DFS(int depth)
{
	if (depth == 81)
	{
		bFinished = true;

		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				cout << Cur[i][j];
			}
			cout << '\n';
		}

		return;
	}

	int r = depth / 9;
	int c = depth % 9;
	if (Cur[r][c])
	{
		DFS(depth + 1);
		return;
	}

	for (int dir = 0; dir < 2; ++dir) {
		int nr = r + DY[dir], nc = c + DX[dir];
		if (IsValid(nr, nc) == false || Cur[nr][nc])
		{
			continue;
		}

		for (int a = 1; a <= 9; ++a) {
			for (int b = a + 1; b <= 9; ++b) {
				if (a == b || Used[min(a, b)][max(a, b)])
				{
					continue;
				}

				Cur[r][c] = a;
				Cur[nr][nc] = b;
				if (IsValidPut(r, c) && IsValidPut(nr, nc))
				{
					Used[min(a, b)][max(a, b)] = true;
					DFS(depth + 1);
					Used[min(a, b)][max(a, b)] = false;
					if (bFinished)
					{
						return;
					}
				}

				Cur[r][c] = b;
				Cur[nr][nc] = a;
				if (IsValidPut(r, c) && IsValidPut(nr, nc))
				{
					Used[min(a, b)][max(a, b)] = true;
					DFS(depth + 1);
					Used[min(a, b)][max(a, b)] = false;
					if (bFinished)
					{
						return;
					}
				}

				Cur[r][c] = Cur[nr][nc] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T = 0;
	while (true)
	{
		bFinished = false;

		memset(Cur, 0, sizeof(Cur));
		memset(Used, false, sizeof(Used));

		int N;
		cin >> N;
		if (N == 0)
		{
			break;
		}

		while (N--)
		{
			int A, B;
			string AS, BS;
			cin >> A >> AS >> B >> BS;
			Cur[AS[0] - 'A'][AS[1] - '0' - 1] = A;
			Cur[BS[0] - 'A'][BS[1] - '0' - 1] = B;
			Used[min(A, B)][max(A, B)] = true;
		}

		for (int i = 1; i <= 9; ++i)
		{
			string S;
			cin >> S;
			Cur[S[0] - 'A'][S[1] - '0' - 1] = i;
		}

		cout << "Puzzle " << ++T << '\n';
		DFS(0);
	}
}