#include <iostream>
using namespace std;

typedef int(*matrix)[5];

int N;
int Mat[5][5] = {};

void Mul(matrix A, matrix B)
{
	int C[5][5] = {};

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				C[i][j] += (A[i][k] * B[k][j]);
			}
			
			C[i][j] %= 1000;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			A[i][j] = C[i][j];
		}
	}
}

void Print(const matrix& A)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	long long B;
	cin >> N >> B;

	int Result[5][5] = {};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Mat[i][j];
		}

		Result[i][i] = 1;
	}

	while (B > 0)
	{
		if (B % 2 == 1)
		{
			Mul(Result, Mat);
		}

		Mul(Mat, Mat);
		B /= 2;
	}

	Print(Result);
}