#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int sum = 0;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		sum += b % a;
	}

	cout << sum;
}