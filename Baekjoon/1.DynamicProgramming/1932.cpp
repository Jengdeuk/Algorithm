#include <iostream>
using namespace std;

int Triangle[501][501];
int DP[501][501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	cin >> Triangle[1][1];
	DP[1][1] = Triangle[1][1];

	int Max = DP[1][1];

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cin >> Triangle[i][j];

			if (j == 1)
			{
				DP[i][j] = DP[i - 1][j] + Triangle[i][j];
			}
			else if (j == i)
			{
				DP[i][j] = DP[i - 1][j - 1] + Triangle[i][j];
			}
			else
			{
				DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + Triangle[i][j];
			}

			if (i == N && DP[i][j] > Max)
			{
				Max = DP[i][j];
			}
		}
	}
	
	cout << Max;
}