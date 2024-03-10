#include <iostream>
using namespace std;

long long Sequence[200001];
long long Sum[200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, Q;
	cin >> N >> Q;

	for (int i = 1; i <= N; ++i)
	{
		cin >> Sequence[i];
		Sum[i] += Sum[i - 1] + Sequence[i];
	}

	int Start = 1;
	for (int i = 0; i < Q; ++i)
	{
		int Query;
		cin >> Query;

		if (Query == 1)
		{
			int Num;
			cin >> Num;
			Start = (Start - Num < 1) ? N + Start - Num : Start - Num;
		}
		else if (Query == 2)
		{
			int Num;
			cin >> Num;
			Start = (Start + Num > N) ? Start + Num - N : Start + Num;
		}
		else
		{
			int A, B;
			cin >> A >> B;
			A = (Start + A - 1 > N) ? Start + A - 1 - N : Start + A - 1;
			B = (Start + B - 1 > N) ? Start + B - 1 - N : Start + B - 1;

			if (A <= B)
			{
				cout << Sum[B] - Sum[A - 1] << '\n';
			}
			else
			{
				cout << Sum[N] - Sum[A - 1] + Sum[B] << '\n';
			}
		}
	}
}