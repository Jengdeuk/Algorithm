#include <iostream>
using namespace std;

int DP[1025][1025];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int Number;
			cin >> Number;
			DP[i][j] = DP[i][j - 1] + DP[i - 1][j] - DP[i - 1][j - 1] + Number;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;
		cout << DP[X2][Y2] + DP[X1 - 1][Y1 - 1] - DP[X1 - 1][Y2] - DP[X2][Y1 - 1] << '\n';
	}
}