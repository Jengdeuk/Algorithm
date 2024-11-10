#include <iostream>
using namespace std;

typedef long long ll;

int N, SI;
ll S[2 << 20];

ll Sum(int A, int B)
{
	ll Ret = 0;

	int L = SI + A;
	int R = SI + B;
	while (L <= R)
	{
		if (L % 2 == 1)
		{
			Ret += S[L];
		}

		if (R % 2 == 0)
		{
			Ret += S[R];
		}

		L = (L + 1) / 2;
		R = (R - 1) / 2;
	}

	return Ret;
}

void Modify(int I, int K)
{
	int Idx = SI + I;
	S[Idx] = K;
	while (Idx > 1)
	{
		int Parent = Idx / 2;
		if (Idx % 2 == 0)
		{
			S[Parent] = S[Idx] + S[Idx + 1];
		}
		else
		{
			S[Parent] = S[Idx - 1] + S[Idx];
		}
		Idx = Parent;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int M;
	cin >> N >> M;

	int K = 0;
	while ((2 << K) < N)
	{
		++K;
	}
	SI = (2 << K);

	for (int i = 0; i < M; ++i)
	{
		int Q, A, B;
		cin >> Q >> A >> B;
		if (Q == 0)
		{
			if (A > B)
			{
				int Temp = A;
				A = B;
				B = Temp;
			}
			cout << Sum(A - 1, B - 1) << '\n';
		}
		else
		{
			Modify(A - 1, B);
		}
	}
}