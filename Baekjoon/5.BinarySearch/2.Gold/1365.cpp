#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lis;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	lis.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (lis.empty() || num > lis.back())
		{
			lis.emplace_back(num);
		}
		else
		{
			int idx = lower_bound(lis.begin(), lis.end(), num) - lis.begin();
			lis[idx] = num;
		}
	}

	cout << n - lis.size();
}