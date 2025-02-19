#include <iostream>
using namespace std;

int n, dp[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	cout << (n % 2 == 0 ? "SK" : "CY");
}