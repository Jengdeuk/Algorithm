#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	vector<int> seq;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (seq.empty() || num > seq.back())
		{
			seq.emplace_back(num);
		}
		else
		{
			int idx = lower_bound(seq.begin(), seq.end(), num) - seq.begin();
			seq[idx] = num;
		}
	}

	cout << n - seq.size();
}