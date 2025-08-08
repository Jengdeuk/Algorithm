#include <iostream>
using namespace std;

const int Inf = 1234567890;

int N, D[501][501];

void Floydwarshall()
{
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (i == j || k == i || k == j || D[i][k] == Inf || D[k][j] == Inf)
				{
					continue;
				}

				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
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
		int Src, Dst;
		cin >> Src >> Dst;
		D[Src][Dst] = 1;
	}

	Floydwarshall();

	int Sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		int Cnt = 0;
		for (int j = 1; j <= N; ++j)
		{
			if (i != j && (D[i][j] != Inf || D[j][i] != Inf))
			{
				Cnt++;
			}
		}
		
		Sum += (Cnt == N - 1);
	}

	cout << Sum;
}