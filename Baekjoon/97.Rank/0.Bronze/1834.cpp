#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	ll Sum = 0;
	ll Idx = 0;
	while (++Idx < N)
	{
		Sum += Idx * N + Idx;
	}

	cout << Sum;
}