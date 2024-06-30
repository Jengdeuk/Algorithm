#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	ll M = 1;
	while (N)
	{
		M *= N--;
	}

	cout << M;
}