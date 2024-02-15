#include <iostream>
using namespace std;

int DP[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;

	DP[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		if ((i - 1) % 2 == 1)
		{
			DP[i] = DP[i - 1] * 2 + 1;
		}
		else
		{
			DP[i] = DP[i - 1] * 2 - 1;
		}
		DP[i] %= 10007;
	}

	cout << DP[N];
}