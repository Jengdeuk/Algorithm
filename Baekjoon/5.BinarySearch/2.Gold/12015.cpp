#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> LIS;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int Number;
	cin >> Number;
	LIS.emplace_back(Number);
	for (int i = 1; i < N; ++i)
	{
		cin >> Number;
		if (Number < LIS.back())
		{
			int Index = lower_bound(LIS.begin(), LIS.end(), Number) - LIS.begin();
			LIS[Index] = Number;
		}
		else if (Number > LIS.back())
		{
			LIS.emplace_back(Number);
		}
	}

	cout << LIS.size();
}