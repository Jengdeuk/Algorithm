#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll H[200000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> H[i];
	}

	sort(H, H + N, greater<>());

	ll MaxH = H[0];
	ll Sum = H[0];
	for (int i = 1; i < N; ++i)
	{
		H[i] += Sum;
		Sum = H[i] + Sum;
		Sum %= 1000000007;
	}

	cout << Sum;
}