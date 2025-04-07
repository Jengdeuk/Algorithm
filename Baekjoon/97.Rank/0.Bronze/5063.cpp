#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int r, e, c;
		cin >> r >> e >> c;

		int n = e - c;
		if (n > r)
			cout << "advertise\n";
		else if (n < r)
			cout << "do not advertise\n";
		else
			cout << "does not matter\n";
	}
}