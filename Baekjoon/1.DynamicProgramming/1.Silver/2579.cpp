#include <iostream>
using namespace std;

int StairScores[301];
int DP[301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> StairScores[i];
	}

	DP[1] = StairScores[1];
	DP[2] = StairScores[1] + StairScores[2];
	DP[3] = max(StairScores[1] + StairScores[3], StairScores[2] + StairScores[3]);
	for (int i = 4; i <= N; ++i)
	{
		DP[i] = max(DP[i - 2] + StairScores[i], DP[i - 3] + StairScores[i - 1] + StairScores[i]);
	}

	cout << DP[N];
}