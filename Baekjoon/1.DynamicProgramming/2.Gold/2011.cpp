#include <iostream>
#include <string>
using namespace std;

int DP[5000][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	if (S[0] == '0')
	{
		cout << 0;
		return 0;
	}

	DP[0][0] = 1;
	for (int i = 1; i < S.size(); ++i)
	{
		int N = (S[i - 1] - '0') * 10 + (S[i] - '0');
		if (S[i] == '0' && N != 10 && N != 20)
		{
			cout << 0;
			return 0;
		}

		if (N == 10 || N == 20)
		{
			DP[i][1] = DP[i - 1][0];
		}
		else if (N >= 11 && N <= 26)
		{
			DP[i][0] = (DP[i - 1][0] + DP[i - 1][1]) % 1000000;
			DP[i][1] = DP[i - 1][0];
		}
		else
		{
			DP[i][0] = (DP[i - 1][0] + DP[i - 1][1]) % 1000000;
		}
	}

	cout << (DP[S.size() - 1][0] + DP[S.size() - 1][1]) % 1000000;
}