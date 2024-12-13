#include <iostream>
using namespace std;

int L, N;
int Cake[1000], RCnt[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> L >> N;

	int MaxCnt = 0, MaxRCnt = 0;
	int Idx = 0, RIdx = 0;
	for (int i = 1; i <= N; ++i)
	{
		int A, B;
		cin >> A >> B;

		for (int j = A; j <= B; ++j)
		{
			if (Cake[j] == 0)
			{
				Cake[j] = i;
				++RCnt[i];
			}
		}

		int Cnt = B - A + 1;
		if (Cnt > MaxCnt)
		{
			MaxCnt = Cnt;
			Idx = i;
		}

		if (RCnt[i] > MaxRCnt)
		{
			MaxRCnt = RCnt[i];
			RIdx = i;
		}
	}

	cout << Idx << '\n';
	cout << RIdx;
}