#include <iostream>
using namespace std;

int Sequence[1000];
int Length[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int MaxLength = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Sequence[i];

		for (int j = 0; j < i; ++j)
		{
			if (Sequence[j] < Sequence[i]
				&& Length[j] > Length[i])
			{
				Length[i] = Length[j];
			}
		}

		Length[i] += 1;
		if (Length[i] > MaxLength)
		{
			MaxLength = Length[i];
		}
	}

	cout << MaxLength;
}