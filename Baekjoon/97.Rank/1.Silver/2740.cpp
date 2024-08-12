#include <iostream>
using namespace std;

int N, M, K;
int A[100][100], B[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> A[i][j];
		}
	}

	cin >> M >> K;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			int Sum = 0;
			for (int k = 0; k < M; ++k)
			{
				Sum += A[i][k] * B[k][j];
			}

			cout << Sum << ' ';
		}

		cout << '\n';
	}
}