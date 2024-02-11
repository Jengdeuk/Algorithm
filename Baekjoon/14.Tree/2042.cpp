#include <iostream>
#include <cmath>
using namespace std;

int Count, StartIndex;
long long SegmentTree[1048576 * 2];

void UpdateTree(int N, int Index, long long Value)
{
	int Current = StartIndex + Index;
	SegmentTree[Current] = Value;

	for (int i = Current / 2; i > 0; i /= 2)
	{
		SegmentTree[i] = SegmentTree[2 * i] + SegmentTree[2 * i + 1];
	}
}

void PrintSum(int N, int Start, int End)
{
	int CurStart = StartIndex + Start;
	int CurEnd = StartIndex + End;

	long long Sum = 0;

	while (CurStart <= CurEnd)
	{
		if (CurStart % 2 == 1)
		{
			Sum += SegmentTree[CurStart];
		}

		if (CurEnd % 2 == 0)
		{
			Sum += SegmentTree[CurEnd];
		}

		CurStart = (CurStart + 1) / 2;
		CurEnd = (CurEnd - 1) / 2;
	}

	cout << Sum << '\n';
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
		cin >> SegmentTree[i];
	}

	for (int i = StartIndex - 1; i > 0; --i)
	{
		SegmentTree[i] = SegmentTree[2 * i] + SegmentTree[2 * i + 1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	InitTree(N);

	for (int i = 0; i < M + K; ++i)
	{
		long long A, B, C;
		cin >> A >> B >> C;

		if (A == 1)
		{
			UpdateTree(N, B - 1, C);
		}
		else if (A == 2)
		{
			PrintSum(N, B - 1, C - 1);
		}
	}
}