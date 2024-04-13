#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> m;
const int Mod = 1e9 + 7;

m Matrix =
{
	{0, 1, 1, 0, 0, 0, 0, 0},
	{1, 0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 0, 1},
	{0, 0, 0, 1, 1, 0, 1, 0},
	{0, 0, 0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 0, 1, 0}
};

m Mul(m A, m B)
{
	m New(8, vector<ll>(8));
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			for (int k = 0; k < 8; ++k)
			{
				New[i][j] += (A[i][k] * B[k][j]) % Mod;
				New[i][j] %= Mod;
			}
		}
	}

	return New;
}

m Divide(m Mat, int Num)
{
	if (Num == 1)
	{
		return Mat;
	}

	if (Num % 2 == 0)
	{
		m A = Divide(Mat, Num / 2);
		return Mul(A, A);
	}
	else
	{
		return Mul(Divide(Mat, Num - 1), Mat);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int D;
	cin >> D;
	Matrix = Divide(Matrix, D);
	cout << Matrix[0][0];
}