#include <iostream>
using namespace std;

int Num[10001];
int H[1001][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int Max = 0;
	for (int i = 1; i <= M; ++i)
	{
		int H1, H2;
		cin >> H1 >> H2;
		Num[H1] = i;
		Num[H2] = i;
	}

	int Index = 1;
	for (int i = 1; i < 10001; ++i)
	{
		if (Num[i] != 0)
		{
			if (H[Num[i]][0] == 0)
			{
				H[Num[i]][0] = Index;
			}
			else
			{
				H[Num[i]][1] = Index;
			}

			++Index;
		}
	}

	int Hands = 2 * M;
	for (int i = 1; i <= M; ++i)
	{
		int H1 = H[i][0];
		int H2 = H[i][1];

		for (int j = 0; H1 + Hands * j <= N; ++j)
		{
			if (H1 + Hands * j == N)
			{
				cout << i;
				exit(0);
			}
		}

		for (int j = 0; H2 + Hands * j <= N; ++j)
		{
			if (H2 + Hands * j == N)
			{
				cout << i;
				exit(0);
			}
		}
	}
}