#include <iostream>
#include <algorithm>
using namespace std;

int N, X;
int S[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}
	cin >> X;

	sort(S, S + N);

	int Cnt = 0;
	int L = 0, R = N - 1;
	while (L < R)
	{
		int Sum = S[L] + S[R];

		if (Sum == X)
		{
			++Cnt;
			++L;
			--R;
		}
		else if (Sum < X)
		{
			++L;
		}
		else
		{
			--R;
		}
	}

	cout << Cnt;
}