#include <iostream>
#include <string>
using namespace std;

int N, M, DP[4001][4001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string A, B;
	cin >> A >> B;
	N = A.size();
	M = B.size();

	int Answer = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (A[i - 1] == B[j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}

			Answer = max(Answer, DP[i][j]);
		}
	}

	cout << Answer;
}