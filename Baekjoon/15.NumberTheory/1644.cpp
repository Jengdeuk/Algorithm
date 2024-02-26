#include <iostream>
#include <vector>
using namespace std;

bool Prime[4000001];
vector<int> Sequence;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 2; i <= N; ++i)
	{
		Prime[i] = true;
	}

	for (int i = 2; i <= N / 2; ++i)
	{
		if (!Prime[i])
		{
			continue;
		}

		for (int j = 2; i * j <= N; ++j)
		{
			Prime[i * j] = false;
		}
	}

	Sequence.reserve(N);
	for (int i = 2; i <= N; ++i)
	{
		if (Prime[i])
		{
			Sequence.emplace_back(i);
		}
	}

	int Cnt = 0;
	int Size = Sequence.size();

	int S = 0;
	int E = 0;
	while (S < Size && E < Size)
	{
		int Sum = 0;
		for (int i = S; i <= E; ++i)
		{
			Sum += Sequence[i];
		}

		if (Sum == N)
		{
			++Cnt;
			++S;
			++E;
		}
		else if (Sum > N)
		{
			++S;
		}
		else
		{
			++E;
		}
	}

	cout << Cnt;
}