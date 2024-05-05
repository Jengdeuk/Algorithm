#include <iostream>
#include <algorithm>
using namespace std;

int Price[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Price[i];
	}

	sort(Price, Price + N);

	int Idx = 0, Cnt = 1;
	for (int i = 1; i < N; ++i)
	{
		if (Price[i] >= 2 * Price[Idx])
		{
			Idx = i;
			++Cnt;
		}
	}

	cout << Cnt;
}