#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	bool b[4] = { false, true, false, false };

	int m;
	cin >> m;
	while (m--)
	{
		int p, q;
		cin >> p >> q;

		bool temp = b[p];
		b[p] = b[q];
		b[q] = temp;
	}

	for (int i = 1; i <= 3; ++i)
		if (b[i])
			cout << i;
}