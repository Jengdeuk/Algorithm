#include <iostream>
#include <cmath>
using namespace std;

int N;
long long Capital[10001];
long long Sum[20001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Capital[i];
	}

	for (int i = 1; i <= 2 * N; ++i)
	{
		Sum[i] = Sum[i - 1] + Capital[(i > N) ? i - N : i];
	}

	long long SS = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j <= N - 2; ++j)
		{
			long long S = Sum[i + j] - Sum[i - 1];
			if (S < 0)
			{
				SS += ceil(double(abs(S)) / Sum[N]);
			}
		}
	}

	cout << SS;
}