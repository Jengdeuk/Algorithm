#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	long long A, B, C;
	cin >> A >> B >> C;

	long long D = C - B;
	if (D <= 0)
	{
		cout << -1;
	}
	else
	{
		cout << A / D + 1;
	}
}