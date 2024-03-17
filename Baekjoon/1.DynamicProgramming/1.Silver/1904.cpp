#include <iostream>
using namespace std;

int DP[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	DP[1] = 1;
	DP[2] = 2;

	for (int i = 3; i <= N; ++i)
	{
		DP[i] = (DP[i - 2] + DP[i - 1]) % 15746;
	}

	cout << DP[N];
}