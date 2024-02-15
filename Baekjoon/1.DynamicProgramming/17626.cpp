#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int DP[50001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		int MinCount = INT_MAX;
		for (int j = 1; j <= sqrt(i); ++j)
		{
			int CurrentNumber = j * j;
			if (CurrentNumber == i)
			{
				DP[i] = 1;
				break;
			}

			int Count = DP[i - CurrentNumber] + 1;
			if (Count < MinCount)
			{
				DP[i] = Count;
				MinCount = Count;
			}
		}
	}

	cout << DP[N];
}