#include <iostream>
#include <algorithm>
using namespace std;

int Rope[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Rope[i];
	}

	sort(Rope, Rope + N);
	
	int Max = 0;
	for (int i = 0; i < N; ++i)
	{
		int Num = N - i;
		Max = max(Max, Rope[i] * Num);
	}

	cout << Max;
}