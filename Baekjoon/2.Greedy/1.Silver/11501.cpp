#include <iostream>
using namespace std;

typedef long long ll;

int N, S[1000000], M[1000000];

void Test()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	int MS = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		MS = max(MS, S[i]);
		M[i] = MS;
	}

	ll Num = 0, Cost = 0, Get = 0;
	for (int i = 0; i < N; ++i)
	{
		if (S[i] < M[i])
		{
			Num++;
			Cost += S[i];
		}
		else
		{
			Get += Num * S[i] - Cost;
			Num = 0;
			Cost = 0;
		}
	}

	cout << Get << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) Test();
}