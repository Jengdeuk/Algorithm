#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int idx = 1, cnt = 0;
	while (idx * idx <= n)
	{
		cnt++;
		idx++;
	}

	cout << cnt;
}