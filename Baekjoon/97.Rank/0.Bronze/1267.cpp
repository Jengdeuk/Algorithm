#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int y = 0, m = 0;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		y += (t / 30) * 10 + 10;
		m += (t / 60) * 15 + 15;
	}

	if (y > m)
	{
		cout << "M " << m;
	}
	else if (y < m)
	{
		cout << "Y " << y;
	}
	else
	{
		cout << "Y M " << y;
	}
}