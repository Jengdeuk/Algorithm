#include <iostream>
using namespace std;

const int length = 24;

int n, k;

bool HasFinished()
{
	int cnt = 0;
	for (int i = 0; i < length; ++i)
	{
		cnt += (n & (1 << i) ? 1 : 0);
	}

	return cnt <= k;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k;

	int cnt = 0;
	while (!HasFinished())
	{
		int cst = (n & -n);
		n += cst;
		cnt += cst;
	}

	cout << cnt;
}