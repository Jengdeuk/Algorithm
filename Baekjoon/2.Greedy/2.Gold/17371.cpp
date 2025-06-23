#include <iostream>
using namespace std;

typedef pair<int, int> p;

int N;
p P[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> P[i].first >> P[i].second;
	}

	int MinPoint = 0;
	int MinDst = 1234567890;
	for (int i = 0; i < N; ++i)
	{
		int MaxDst = 0;
		for (int j = 0; j < N; ++j)
		{
			if (i == j)
			{
				continue;
			}

			MaxDst = max(MaxDst, (P[i].first - P[j].first) * (P[i].first - P[j].first) + (P[i].second - P[j].second) * (P[i].second - P[j].second));
		}

		if (MaxDst < MinDst)
		{
			MinPoint = i;
			MinDst = MaxDst;
		}
	}

	cout << P[MinPoint].first << ' ' << P[MinPoint].second;
}