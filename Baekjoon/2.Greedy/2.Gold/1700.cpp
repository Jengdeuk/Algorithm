#include <iostream>
#include <cstring>
using namespace std;

int N, K, On;
int O[100], R[101];
bool M[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < K; ++i)
	{
		cin >> O[i];
	}

	int Off = 0;
	for (int i = 0; i < K; ++i)
	{
		if (M[O[i]])
		{
			continue;
		}
		else if (On < N)
		{
			++On;
			M[O[i]] = true;
			continue;
		}

		memset(R, 0, sizeof(R));

		int Idx = 1;
		for (int j = i + 1; j < K; ++j)
		{
			if (M[O[j]] && R[O[j]] == 0)
			{
				R[O[j]] = Idx++;
			}
		}

		bool bFound = false;
		int FI = 0;
		for (int j = 1; j <= K; ++j)
		{
			if (M[j] && R[j] == 0)
			{
				bFound = true;
				FI = j;
				break;
			}
		}

		if (!bFound)
		{
			for (int j = 1; j <= K; ++j)
			{
				if (M[j] && R[j] == Idx - 1)
				{
					FI = j;
					break;
				}
			}
		}

		++Off;
		M[FI] = false;
		M[O[i]] = true;
	}

	cout << Off;
}