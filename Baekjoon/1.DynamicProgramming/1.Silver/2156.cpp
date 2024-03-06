#include <iostream>
using namespace std;

int W[10001];
int DP[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	cin >> W[1];
	DP[1] = W[1];
	if (N >= 2)
	{
		cin >> W[2];
		DP[2] = DP[1] + W[2];

		for (int i = 3; i <= N; ++i)
		{
			cin >> W[i];
			DP[i] = max(DP[i - 1], max(DP[i - 2] + W[i], DP[i - 3] + W[i - 1] + W[i]));
		}
	}

	cout << DP[N];
}