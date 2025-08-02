#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll N;
	cin >> N;
	N %= 5;
	if (N == 0 || N == 2)
	{
		cout << "CY";
	}
	else
	{
		cout << "SK";
	}
}