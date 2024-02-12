#include <iostream>
#include <cmath>
using namespace std;

const int& DivNum = 1000000007;

int Count, StartIndex;
long long MulTree[1048576 * 2];

void UpdateValue(int Index, int Value)
{
	int CurIndex = StartIndex + Index;

	MulTree[CurIndex] = Value;
	CurIndex /= 2;

	while (CurIndex > 0)
	{
		if (MulTree[2 * CurIndex] == -1)
		{
			MulTree[CurIndex] = MulTree[2 * CurIndex + 1];
		}
		else if (MulTree[2 * CurIndex + 1] == -1)
		{
			MulTree[CurIndex] = MulTree[2 * CurIndex];
		}
		else
		{
			MulTree[CurIndex] = MulTree[2 * CurIndex] * MulTree[2 * CurIndex + 1] % DivNum;
		}

		CurIndex /= 2;
	}
}

void SearchMulValue(int Start, int End)
{
	int CurStart = StartIndex + Start;
	int CurEnd = StartIndex + End;

	long long Mul = 1;
	while (CurStart <= CurEnd)
	{
		if (CurStart % 2 == 1
			&& MulTree[CurStart] != -1)
		{
			Mul = Mul * MulTree[CurStart] % DivNum;
		}

		if (CurEnd % 2 == 0
			&& MulTree[CurEnd] != -1)
		{
			Mul = Mul * MulTree[CurEnd] % DivNum;
		}

		CurStart = (CurStart + 1) / 2;
		CurEnd = (CurEnd - 1) / 2;
	}
	cout << Mul << '\n';
}

void InitTree(int N)
{
	for (int i = 0; i < 1048576 * 2; ++i)
	{
		MulTree[i] = -1;
	}

	while (pow(2, Count) < N)
	{
		++Count;
	}
	StartIndex = pow(2, Count);

	for (int i = StartIndex; i < StartIndex + N; ++i)
	{
		cin >> MulTree[i];
	}

	for (int i = StartIndex - 1; i > 0; --i)
	{
		if (MulTree[2 * i] == -1)
		{
			MulTree[i] = MulTree[2 * i + 1];
		}
		else if (MulTree[2 * i + 1] == -1)
		{
			MulTree[i] = MulTree[2 * i];
		}
		else
		{
			MulTree[i] = MulTree[2 * i] * MulTree[2 * i + 1] % DivNum;
		}
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
		int Command, A, B;
		cin >> Command >> A >> B;

		if (Command == 1)
		{
			UpdateValue(A - 1, B);
		}
		else if (Command == 2)
		{
			SearchMulValue(A - 1, B - 1);
		}
	}
}