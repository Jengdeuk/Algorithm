#include <iostream>
#include <climits>
using namespace std;

const int Inf = INT_MAX;

int N, D[201][201], P[201][201];
bool Direct[201][201];

int FindRoot(int Src, int Dst)
{
	if (Direct[Src][P[Src][Dst]])
	{
		return P[Src][Dst];
	}

	return P[Src][Dst] = FindRoot(Src, P[Src][Dst]);
}

void FloydWarshall()
{
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (k == i || k == j || i == j || D[i][k] == Inf || D[k][j] == Inf)
				{
					continue;
				}

				int ND = D[i][k] + D[k][j];
				if (ND < D[i][j])
				{
					D[i][j] = ND;
					P[i][j] = FindRoot(i, k);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
			{
				continue;
			}

			D[i][j] = Inf;
		}
	}

	int M;
	cin >> M;
	while (M--)
	{
		int A, B, T;
		cin >> A >> B >> T;
		if (T >= D[A][B])
		{
			continue;
		}

		D[A][B] = T;
		D[B][A] = T;
		P[A][B] = B;
		P[B][A] = A;
		Direct[A][B] = true;
		Direct[B][A] = true;
	}

	FloydWarshall();

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (P[i][j] > 0)
			{
				cout << P[i][j];
			}
			else
			{
				cout << '-';
			}
			cout << ' ';
		}
		cout << '\n';
	}
}