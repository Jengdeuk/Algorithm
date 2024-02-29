#include <iostream>
using namespace std;

int Num[2000];
bool DP[2000][2000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> Num[i];
	}

	for (int i = 0; i < N; ++i)
	{
		DP[i][i] = true;

		if (i < N - 1)
		{
			DP[i][i + 1] = (Num[i] == Num[i + 1]);
		}
	}

	for (int i = N - 3; i >= 0; --i)
	{
		for (int j = i + 2; j < N; ++j)
		{
			DP[i][j] = (Num[i] == Num[j] && DP[i + 1][j - 1]);
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int S, E;
		cin >> S >> E;
		cout << DP[S - 1][E - 1] << '\n';
	}
}