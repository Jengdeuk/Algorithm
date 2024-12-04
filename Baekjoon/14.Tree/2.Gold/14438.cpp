#include <iostream>
using namespace std;

const int MaxSize = 2 << 17;
const int Infinite = 1000000001;

int N, SI;
int ST[MaxSize];

void InitTree()
{
	cin >> N;

	int K = 0;
	while ((2 << K) < N)
	{
		++K;
	}

	SI = (2 << K);

	for (int i = 0; i < N; ++i)
	{
		cin >> ST[SI + i];
	}

	for (int i = N; i < SI; ++i)
	{
		ST[SI + i] = Infinite;
	}

	for (int i = SI - 1; i > 0; --i)
	{
		ST[i] = min(ST[2 * i], ST[2 * i + 1]);
	}
}

void Modify(int Idx, int Value)
{
	Idx += SI;
	ST[Idx] = Value;

	int Parent;
	while ((Parent = (Idx >> 1)) >= 1)
	{
		if (Idx % 2 == 0)
		{
			ST[Parent] = min(ST[Idx], ST[Idx + 1]);
		}
		else
		{
			ST[Parent] = min(ST[Idx - 1], ST[Idx]);
		}
		Idx = Parent;
	}
}

void PrintMinimum(int L, int R)
{
	int Ret = Infinite;

	L += SI;
	R += SI;
	while (L <= R)
	{
		if (L % 2 == 1)
		{
			Ret = min(Ret, ST[L]);
		}

		if (R % 2 == 0)
		{
			Ret = min(Ret, ST[R]);
		}

		L = ((L + 1) >> 1);
		R = ((R - 1) >> 1);
	}

	cout << Ret << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	InitTree();

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		if (A == 1)
		{
			Modify(B - 1, C);
		}
		else
		{
			PrintMinimum(B - 1, C - 1);
		}
	}
}