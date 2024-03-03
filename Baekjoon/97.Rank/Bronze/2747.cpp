#include <iostream>
using namespace std;

int DP[46];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	DP[0] = 0;
	DP[1] = 1;

	int N;
	cin >> N;
	for (int i = 2; i <= N; ++i)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[N];
}