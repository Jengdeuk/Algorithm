#include <iostream>
using namespace std;

pair<int, int> DP[41];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	DP[0] = make_pair<int, int>(1, 0);
	DP[1] = make_pair<int, int>(0, 1);
	for (int i = 2; i < 41; ++i)
	{
		DP[i].first = DP[i - 1].first + DP[i - 2].first;
		DP[i].second = DP[i - 1].second + DP[i - 2].second;
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int Number;
		cin >> Number;
		cout << DP[Number].first << ' ' << DP[Number].second << '\n';
	}
}