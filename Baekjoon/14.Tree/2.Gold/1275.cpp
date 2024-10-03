#include <iostream>
using namespace std;

typedef long long ll;

const int MaxSize = (1 << 17) * 2;

int N, K, S;
ll Tree[MaxSize];

ll Sum(int X, int Y)
{
	ll Answer = 0;

	while (X <= Y)
	{
		if (X % 2 == 1)
		{
			Answer += Tree[X];
		}

		if (Y % 2 == 0)
		{
			Answer += Tree[Y];
		}

		X = ((X + 1) >> 1);
		Y = ((Y - 1) >> 1);
	}

	return Answer;
}

void Replace(int A, int B)
{
	Tree[A] = B;
	while (A > 1)
	{
		int Ci = (A % 2 == 0 ? 1 : -1);
		Tree[A / 2] = Tree[A] + Tree[A + Ci];
		A = (A >> 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Q;
	cin >> N >> Q;

	K = 0;
	while ((1 << K) < N)
	{
		++K;
	}

	S = (1 << K);
	for (int i = S; i < S + N; ++i)
	{
		cin >> Tree[i];
	}

	for (int i = S - 1; i >= 1; --i)
	{
		Tree[i] = Tree[2 * i] + Tree[2 * i + 1];
	}

	for (int i = 0; i < Q; ++i)
	{
		int X, Y, A, B;
		cin >> X >> Y >> A >> B;
		if (X > Y)
		{
			int Temp = X;
			X = Y;
			Y = Temp;
		}

		X = S + X - 1;
		Y = S + Y - 1;
		cout << Sum(X, Y) << '\n';

		A = S + A - 1;
		Replace(A, B);
	}
}