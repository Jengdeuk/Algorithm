#include <iostream>
#include <climits>
using namespace std;

int Height[501][501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, B;
	cin >> N >> M >> B;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Height[i][j];
		}
	}

	int MinTime = INT_MAX;
	int SolutionHeight = 0;
	for (int TargetHeight = 0; TargetHeight < 257; ++TargetHeight)
	{
		int Time = 0;
		int Blocks = B;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				int CurrentHeight = Height[i][j];
				if (CurrentHeight > TargetHeight)
				{
					Blocks += (CurrentHeight - TargetHeight);
					Time += (CurrentHeight - TargetHeight) * 2;
				}
				else if (CurrentHeight < TargetHeight)
				{
					Blocks -= (TargetHeight - CurrentHeight);
					Time += (TargetHeight - CurrentHeight);
				}
			}
		}

		if (Blocks < 0)
		{
			continue;
		}

		if (Time <= MinTime)
		{
			MinTime = Time;
			SolutionHeight = TargetHeight;
		}
	}

	cout << MinTime << ' ' << SolutionHeight;
}