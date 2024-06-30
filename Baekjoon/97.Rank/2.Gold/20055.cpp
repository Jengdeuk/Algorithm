#include <iostream>
using namespace std;

int N, K;
int A[200];
bool R[200];

bool Finish()
{
	int Cnt = 0;
	for (int i = 0; i < 2 * N; ++i)
	{
		if (A[i] == 0 && ++Cnt >= K)
		{
			return true;
		}
	}

	return false;
}

void RotLeft(int& Idx)
{
	Idx = (Idx - 1 < 0 ? 2 * N - 1 : Idx - 1);
}

void RotRight(int& Idx)
{
	Idx = (Idx + 1 > 2 * N - 1 ? 0 : Idx + 1);
}

void Move(int S, int E)
{
	int C = E;
	RotLeft(C);
	while (C != S)
	{
		if (!R[C])
		{
			RotLeft(C);
			continue;
		}

		int NC = C;
		RotRight(NC);
		if (!R[NC] && A[NC] > 0)
		{
			R[C] = false;
			R[NC] = (NC == E ? false : true);
			--A[NC];
		}

		RotLeft(C);
	}
}

void Put(int S)
{
	if (A[S] > 0)
	{
		R[S] = true;
		--A[S];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < 2 * N; ++i)
	{
		cin >> A[i];
	}

	int P = 0, S = 0, E = N - 1;
	do
	{
		++P;

		RotLeft(S);
		RotLeft(E);
		R[E] = false;

		Move(S, E);
		Put(S);
	} while (!Finish());

	cout << P;
}