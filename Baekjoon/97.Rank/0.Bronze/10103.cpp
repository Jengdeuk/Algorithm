#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int a = 100, b = 100;
	
	int n;
	cin >> n;
	while (n--)
	{
		int p, q;
		cin >> p >> q;
		if (p < q)
			a -= q;
		else if (q < p)
			b -= p;
	}

	cout << a << '\n';
	cout << b << '\n';
}