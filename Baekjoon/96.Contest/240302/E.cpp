#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	long long N, M;
	cin >> N >> M;

	long long Result = 1;
	while (N > 1)
	{
		Result *= N;
		Result %= M;
		--N;
	}

	cout << Result % M;
}