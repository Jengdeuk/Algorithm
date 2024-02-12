#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long N;
	cin >> N;

	long long P = N;
	for (int i = 2; i <= sqrt(N); ++i)
	{
		if (N % i != 0)
		{
			continue;
		}

		P = P - P / i;
		while (N % i == 0)
		{
			N /= i;
		}
	}

	if (N > 1)
	{
		P = P - P / N;
	}

	cout << P;
}