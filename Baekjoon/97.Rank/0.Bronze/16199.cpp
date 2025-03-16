#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int hy, hm, hd;
	cin >> hy >> hm >> hd;

	int y, m, d;
	cin >> y >> m >> d;

	cout << y - hy + (m == hm ? d >= hd : m > hm) - 1 << '\n';
	cout << y - hy + 1 << '\n';
	cout << y - hy;
}