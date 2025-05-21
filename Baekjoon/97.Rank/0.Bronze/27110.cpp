#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int a, b, c;
	cin >> a >> b >> c;
	cout << (min(n, a) + min(n, b) + min(n, c));
}