#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int prv[3] = {};
	for (int i = 1; i <= n; ++i)
	{
		int cur[3] = {};
		for (int j = 0; j < 3; ++j)
		{
			int cst;
			cin >> cst;
			cur[j] = min(prv[(j + 1) % 3], prv[(j + 2) % 3]) + cst;
		}

		memcpy(prv, cur, sizeof(prv));
	}

	cout << min(prv[0], min(prv[1], prv[2]));
}