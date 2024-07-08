#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, K;
ll S[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}
	sort(S, S + N);

	for (int i = 0; i < N - 1; ++i)
	{
		S[i] = S[i + 1] - S[i];
	}
	sort(S, S + N - 1, greater<>());

	ll Sum = 0;
	for (int i = K - 1; i < N - 1; ++i)
	{
		Sum += S[i];
	}

	cout << Sum;
}