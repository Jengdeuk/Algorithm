#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;

	int c = (a / 2) + b;
	cout << min(n, c);
}