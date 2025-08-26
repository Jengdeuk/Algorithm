#include <iostream>
#include <climits>
using namespace std;

const int Inf = INT_MAX;

int N, D[401][401];

void Floydwarshall()
{
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (k == i || k == j || D[i][k] == Inf || D[k][j] == Inf)
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

	int M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			D[i][j] = Inf;
		}
	}

	while (M--)
	{
		int A, B, C;
		cin >> A >> B >> C;
		D[A][B] = C;
	}

	Floydwarshall();

	int MS = Inf;
	for (int i = 1; i <= N; ++i)
	{
		if (D[i][i] != Inf)
		{
			MS = min(MS, D[i][i]);
		}
	}

	if (MS != Inf)
	{
		cout << MS;
	}
	else
	{
		cout << -1;
	}
}