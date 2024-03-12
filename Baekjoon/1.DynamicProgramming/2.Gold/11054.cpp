#include <iostream>
using namespace std;

int Sequence[1000];
int LengthL[1000];
int LengthR[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Sequence[i];

		for (int j = 0; j < i; ++j)
		{
			if (Sequence[j] < Sequence[i]
				&& LengthL[j] > LengthL[i])
			{
				LengthL[i] = LengthL[j];
			}
		}

		LengthL[i] += 1;
	}

	for (int i = N; i >= 0; --i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (Sequence[j] < Sequence[i]
				&& LengthR[j] > LengthR[i])
			{
				LengthR[i] = LengthR[j];
			}
		}

		LengthR[i] += 1;
	}

	int MaxLength = 0;
	for (int i = 0; i < N; ++i)
	{
		int Length = LengthL[i] + LengthR[i] - 1;
		if (Length > MaxLength)
		{
			MaxLength = Length;
		}
	}

	cout << MaxLength;
}