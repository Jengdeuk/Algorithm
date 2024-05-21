#include <iostream>
using namespace std;

typedef pair<int, int> p;

int N;
p Hole[100001];

int Bin(int S)
{
	int Idx = N;
	int L = 0, R = N - 1;
	while (L <= R)
	{
		int M = (L + R) / 2;
		if (S <= Hole[M].second)
		{
			Idx = min(Idx, Hole[M].first);
		}

		if (Idx > Hole[M].first)
		{
			L = M + 1;
		}
		else
		{
			R = M - 1;
		}
	}

	return Idx;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int H;
		cin >> H;
		Hole[i - 1].first = i;
		Hole[i - 1].second = H + (i - 1);
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		int S;
		cin >> S;
		cout << Bin(S) << ' ';
	}
}