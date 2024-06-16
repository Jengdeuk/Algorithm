#include <iostream>
#include <string>
using namespace std;

int Gear[5][8];
int	I[5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 1; i <= 4; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < 8; ++j)
		{
			Gear[i][j] = S[j] - '0';
		}
	}

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		int N, D;
		cin >> N >> D;

		bool bDiff[4] = {};
		for (int i = 1; i <= 3; ++i)
		{
			int L = 2 - I[i];
			if (L >= 8) L -= 8;
			else if (L < 0) L += 8;

			int R = 6 - I[i + 1];
			if (R >= 8) R -= 8;
			else if (R < 0) R += 8;

			bDiff[i] = (Gear[i][L] != Gear[i + 1][R]);
		}

		int Turn[5] = {};
		Turn[N] = D;
		switch (N)
		{
		case 1:
			if (bDiff[1])
			{
				Turn[2] = -D;
				if (bDiff[2])
				{
					Turn[3] = D;
					if (bDiff[3])
					{
						Turn[4] = -D;
					}
				}
			}
			break;
		case 2:
			if (bDiff[1])
			{
				Turn[1] = -D;
			}
			if (bDiff[2])
			{
				Turn[3] = -D;
				if (bDiff[3])
				{
					Turn[4] = D;
				}
			}
			break;
		case 3:
			if (bDiff[3])
			{
				Turn[4] = -D;
			}
			if (bDiff[2])
			{
				Turn[2] = -D;
				if (bDiff[1])
				{
					Turn[1] = D;
				}
			}
			break;
		case 4:
			if (bDiff[3])
			{
				Turn[3] = -D;
				if (bDiff[2])
				{
					Turn[2] = D;
					if (bDiff[1])
					{
						Turn[1] = -D;
					}
				}
			}
			break;
		}
	
		for (int i = 1; i <= 4; ++i)
		{
			int NI = I[i] + Turn[i];
			I[i] = (NI >= 8 ? 0 : (NI <= -8 ? 0 : NI));
		}
	}

	int Score = 0;
	for (int i = 1; i <= 4; ++i)
	{
		int Idx = -I[i];
		if (Idx >= 8) Idx -= 8;
		else if (Idx < 0) Idx += 8;
		if (Gear[i][Idx])
		{
			Score += (1 << i - 1);
		}
	}

	cout << Score;
}