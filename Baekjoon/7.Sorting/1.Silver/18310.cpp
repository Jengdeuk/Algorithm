#include <iostream>
#include <algorithm>
using namespace std;

int N, S[200000];

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

	cout << S[(N - 1) / 2];
}