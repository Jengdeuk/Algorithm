#include <iostream>
#include <cmath>
using namespace std;

int Count, StartIndex;
int MinTree[131072 * 2];

void SearchMinimumValue(int Start, int End)
{
	int CurStart = StartIndex + Start;
	int CurEnd = StartIndex + End;

	int MinValue = 1000000001;
	while (CurStart <= CurEnd)
	{
		if (CurStart % 2 == 1)
		{
			MinValue = min(MinValue, MinTree[CurStart]);
		}

		if (CurEnd % 2 == 0)
		{
			MinValue = min(MinValue, MinTree[CurEnd]);
		}

		CurStart = (CurStart + 1) / 2;
		CurEnd = (CurEnd - 1) / 2;
	}
	cout << MinValue << '\n';
}

void InitTree(int N)
{
	while (pow(2, Count) < N)
	{
		++Count;
	}
	StartIndex = pow(2, Count);

	for (int i = StartIndex; i < StartIndex + N; ++i)
	{
		cin >> MinTree[i];
	}

	for (int i = StartIndex - 1; i > 0; --i)
	{
		if (MinTree[2 * i] == 0)
		{
			MinTree[i] = MinTree[2 * i + 1];
		}
		else if (MinTree[2 * i + 1] == 0)
		{
			MinTree[i] = MinTree[2 * i];
		}
		else
		{
			MinTree[i] = min(MinTree[2 * i], MinTree[2 * i + 1]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	InitTree(N);

	for (int i = 0; i < M; ++i)
	{
		int Start, End;
		cin >> Start >> End;
		SearchMinimumValue(Start - 1, End - 1);
	}
}