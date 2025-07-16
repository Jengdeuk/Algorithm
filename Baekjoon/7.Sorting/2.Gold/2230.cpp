#include <iostream>
#include <algorithm>
using namespace std;

int N, S[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	sort(S, S + N);

	int Answer = 2000000000;
	int L = 0, R = 1;
	while (R < N && L < R)
	{
		int Gap = S[R] - S[L];
		if (Gap < M)
		{
			R++;
			continue;
		}

		Answer = min(Answer, Gap);
		if (R - L == 1)
		{
			R++;
		}
		else
		{
			L++;
		}
	}

	cout << Answer;
}