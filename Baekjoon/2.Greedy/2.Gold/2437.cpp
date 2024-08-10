#include <iostream>
#include <algorithm>
using namespace std;

int N;
int S[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	sort(S, S + N);

	int K = 0;
	for (int i = 0; i < N; ++i)
	{
		if (S[i] > K + 1)
		{
			break;
		}

		K += S[i];
	}

	cout << K + 1;
}