#include <iostream>
using namespace std;

const int MaxSize = 246912;

bool Prime[MaxSize + 1];
int PrimeSum[MaxSize + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 2; i <= MaxSize; ++i)
	{
		Prime[i] = true;
	}

	for (int i = 2; i <= MaxSize / 2; ++i)
	{
		if (!Prime[i])
		{
			continue;
		}

		for (int j = 2; i * j <= MaxSize; ++j)
		{
			Prime[i * j] = false;
		}
	}

	for (int i = 1; i <= MaxSize; ++i)
	{
		PrimeSum[i] = (Prime[i]) ? PrimeSum[i - 1] + 1 : PrimeSum[i - 1];
	}

	while (true)
	{
		int N;
		cin >> N;
		if (N == 0)
		{
			break;
		}

		cout << PrimeSum[2 * N] - PrimeSum[N] << '\n';
	}
}