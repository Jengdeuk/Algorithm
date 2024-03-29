#include <iostream>
using namespace std;

int DP[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;

	for (int i = 4; i <= N; ++i)
	{
		DP[i] = i;

		for (int j = 1; j * j <= i; ++j)
		{
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}
	
	cout << DP[N];
}