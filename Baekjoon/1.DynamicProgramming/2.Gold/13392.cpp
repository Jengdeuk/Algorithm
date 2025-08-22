#include <iostream>
#include <string>
#include <climits>
using namespace std;

const int Inf = INT_MAX;

int N, DP[10001][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Src, Dst;
	cin >> N >> Src >> Dst;

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			DP[i][j] = Inf;
		}
	}

	for (int j = 0; j < 10; ++j)
	{
		DP[0][j] = j;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			int LCnt = ((Dst[i - 1] - '0') - (Src[i - 1] - '0') - j + 20) % 10;
			int RCnt = 10 - LCnt;
			DP[i][j] = min(DP[i][j], DP[i - 1][j] + RCnt);
			DP[i][(j + LCnt) % 10] = min(DP[i][(j + LCnt) % 10], DP[i - 1][j] + LCnt);
		}
	}

	int Answer = Inf;
	for (int j = 0; j < 10; ++j)
	{
		Answer = min(Answer, DP[N][j]);
	}

	cout << Answer;
}