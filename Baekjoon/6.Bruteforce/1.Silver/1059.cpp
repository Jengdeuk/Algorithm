#include <iostream>
#include <algorithm>
using namespace std;

int L, N;
int S[50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> L;
	for (int i = 0; i < L; ++i)
	{
		cin >> S[i];
	}
	cin >> N;

	sort(S, S + L);

	int LI = lower_bound(S, S + L, N) - S;
	int UI = upper_bound(S, S + L, N) - S;
	if (LI != UI)
	{
		cout << 0;
		return 0;
	}

	int Count = 0;
	int L = S[LI - 1] + 1;
	int R = S[UI] - 1;
	for (int i = L; i < R; ++i)
	{
		for (int j = i + 1; j <= R; ++j)
		{
			if (i > N || j < N)
			{
				continue;
			}

			++Count;
		}
	}

	cout << Count;
}