#include <iostream>
#include <cmath>
using namespace std;

int Count, StartIndex;
int MinTree[131072 * 2];
int MaxTree[131072 * 2];

void SearchTree(int N, int Start, int End)
{
	int CurStart = StartIndex + Start;
	int CurEnd = StartIndex + End;

	int Min = 1000000001;
	int Max = 0;

	while (CurStart <= CurEnd)
	{
		if (CurStart % 2 == 1)
		{
			Min = min(Min, MinTree[CurStart]);
			Max = max(Max, MaxTree[CurStart]);
		}

		if (CurEnd % 2 == 0)
		{
			Min = min(Min, MinTree[CurEnd]);
			Max = max(Max, MaxTree[CurEnd]);
		}

		CurStart = (CurStart + 1) / 2;
		CurEnd = (CurEnd - 1) / 2;
	}

	cout << Min << ' ' << Max << '\n';
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
		int Number;
		cin >> Number;
		MinTree[i] = Number;
		MaxTree[i] = Number;
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

		MaxTree[i] = max(MaxTree[2 * i], MaxTree[2 * i + 1]);
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

		SearchTree(N, Start - 1, End - 1);
	}
}