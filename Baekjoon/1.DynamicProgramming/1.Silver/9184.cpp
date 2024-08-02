#include <iostream>
#include <climits>
using namespace std;

const int MinInt = INT_MIN;

int DP[101][101][101];

int W(int A, int B, int C)
{
	if (DP[A + 50][B + 50][C + 50] != MinInt)
	{
		return DP[A + 50][B + 50][C + 50];
	}

	if (A <= 0 || B <= 0 || C <= 0)
	{
		return DP[A + 50][B + 50][C + 50] = 1;
	}

	if (A > 20 || B > 20 || C > 20)
	{
		return DP[A + 50][B + 50][C + 50] = W(20, 20, 20);
	}

	if (A < B && B < C)
	{
		return DP[A + 50][B + 50][C + 50] = W(A, B, C - 1) + W(A, B - 1, C - 1) - W(A, B - 1, C);
	}

	return DP[A + 50][B + 50][C + 50] = W(A - 1, B, C) + W(A - 1, B - 1, C) + W(A - 1, B, C - 1) - W(A - 1, B - 1, C - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			for (int k = 0; k < 101; ++k)
			{
				DP[i][j][k] = MinInt;
			}
		}
	}

	while (true)
	{
		int A, B, C;
		cin >> A >> B >> C;
		if (A == -1 && B == -1 && C == -1)
		{
			break;
		}

		cout << "w(" << A << ", " << B << ", " << C << ") = " << W(A, B, C) << '\n';
	}
}