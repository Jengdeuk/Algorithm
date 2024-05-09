#include <iostream>
#include <algorithm>
using namespace std;

int Car[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, P;
	cin >> N >> P;
	for (int i = 0; i < N; ++i)
	{
		cin >> Car[i];
	}

	sort(Car, Car + N, greater<>());

	int Max = 0;
	for (int i = 1; i < N; ++i)
	{
		int CurDist = Car[i - 1];
		int DoDist = P * (N - i + 1);
		if (CurDist < DoDist)
		{
			Max = max(Max, DoDist - CurDist);
		}
	}

	cout << Max + Car[N - 1];
}