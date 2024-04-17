#include <iostream>
#include <vector>
using namespace std;

int A[500001];
int Index[500001];
vector<int> LIS;

int LowerBound(int Number)
{
	int L = 0;
	int R = LIS.size() - 1;
	while (L < R)
	{
		int M = (L + R) / 2;
		if (LIS[M] < Number)
		{
			L = M + 1;
		}
		else
		{
			R = M;
		}
	}

	return L;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Ai, Bi;
		cin >> Ai >> Bi;
		A[Ai] = Bi;
	}

	bool bFirst = true;
	for (int Ai = 1; Ai <= 500000; ++Ai)
	{
		if (A[Ai] == 0)
		{
			continue;
		}

		int Bi = A[Ai];
		if (bFirst || Bi > LIS.back())
		{
			bFirst = false;
			LIS.emplace_back(Bi);
			Index[Ai] = LIS.size() - 1;
		}
		else
		{
			int Idx = LowerBound(Bi);
			LIS[Idx] = Bi;
			Index[Ai] = Idx;
		}
	}

	int Idx = LIS.size() - 1;
	for (int Ai = 500000; Ai >= 1; --Ai)
	{
		if (A[Ai] == 0)
		{
			continue;
		}

		if (Index[Ai] == Idx)
		{
			A[Ai] = 0;
			--Idx;
		}
	}

	cout << N - LIS.size() << '\n';
	for (int i = 1; i <= 500000; ++i)
	{
		if (A[i] != 0)
		{
			cout << i << '\n';
		}
	}
}