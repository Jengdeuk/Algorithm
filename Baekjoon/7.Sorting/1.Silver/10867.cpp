#include <iostream>
#include <algorithm>
using namespace std;

int S[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	sort(S, S + N);

	int Pre = -1010;
	for (int i = 0; i < N; ++i)
	{
		if (S[i] == Pre)
		{
			continue;
		}

		cout << S[i] << ' ';
		Pre = S[i];
	}
}