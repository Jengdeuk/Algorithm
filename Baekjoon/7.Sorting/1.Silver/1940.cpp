#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int S[15000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	sort(S, S + N);

	int Cnt = 0;
	int L = 0, R = N - 1;
	while (L < R)
	{
		int Sum = S[L] + S[R];
		if (Sum == M)
		{
			++Cnt;
		}

		if (Sum <= M)
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