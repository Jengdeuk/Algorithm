#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int Set[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	if (N == 0)
	{
		cout << 1;
		return 0;
	}

	while (N != 0)
	{
		++Set[N % 10];
		N /= 10;
	}

	Set[6] = ceil(float(Set[6] + Set[9]) / 2);

	cout << *max_element(Set, Set + 9);
}