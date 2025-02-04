#include <iostream>
using namespace std;

int n, l;
bool h[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> l;

	int hole;
	for (int i = 0; i < n; ++i)
	{
		cin >> hole;
		h[hole] = true;
	}

	int cnt = 0;
	for (int i = 1; i <= 1000; ++i)
	{
		if (h[i])
		{
			++cnt;
			i += l - 1;
		}
	}

	cout << cnt;
}