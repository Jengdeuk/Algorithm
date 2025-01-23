#include <iostream>
#include <algorithm>
using namespace std;

int cnt[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		int num;
		cin >> num;
		sum += num;
		++cnt[num];
	}

	cout << sum / 10 << '\n';
	cout << max_element(cnt, cnt + 1000) - cnt;
}