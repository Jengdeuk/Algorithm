#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m, a;
	cin >> n >> m >> a;
	cout << static_cast<long long>(ceil(static_cast<double>(n) / a)) * static_cast<long long>(ceil(static_cast<double>(m) / a));
}