#include <iostream>
using namespace std;

int Price[1001];
int DP[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Price[i];

		for (int j = 1; j <= i; ++j)
		{
			DP[i] = max(DP[i], DP[i - j] + Price[j]);
		}
	}

	cout << DP[N];
}