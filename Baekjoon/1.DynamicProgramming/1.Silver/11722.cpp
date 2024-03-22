#include <iostream>
using namespace std;

int Sequence[1000];
int DP[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int Max = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Sequence[i];

		for (int j = 0; j < i; ++j)
		{
			if (Sequence[j] > Sequence[i]
				&& DP[j] > DP[i])
			{
				DP[i] = DP[j];
			}
		}

		DP[i] += 1;
		if (DP[i] > Max)
		{
			Max = DP[i];
		}
	}

	cout << Max;
}