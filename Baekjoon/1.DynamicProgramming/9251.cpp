#include <iostream>
#include <string>
using namespace std;

int DP[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string A, B;
	cin >> A >> B;

	int N = A.size();
	int M = B.size();
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (A[i - 1] == B[j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else
			{
				DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
			}
		}
	}

	cout << DP[N][M];
}