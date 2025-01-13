#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int sum = 1;
	for (int i = 0; i < n; ++i)
	{
		int tab;
		cin >> tab;
		sum += tab - 1;
	}

	cout << sum;
}