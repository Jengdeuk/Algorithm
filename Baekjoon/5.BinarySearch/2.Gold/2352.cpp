#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> LIS;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;

		if (LIS.empty())
		{
			LIS.emplace_back(Num);
			continue;
		}

		if (Num > LIS.back())
		{
			LIS.emplace_back(Num);
		}
		else
		{
			int Idx = lower_bound(LIS.begin(), LIS.end(), Num) - LIS.begin();
			LIS[Idx] = Num;
		}
	}

	cout << LIS.size();
}