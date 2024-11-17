#include <iostream>
using namespace std;

typedef long long ll;

ll S[500001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	ll Sum = 0;
	for (int i = 1; i <= N - 2; ++i)
	{
		S[i] = S[i - 1] + i;
		Sum += S[i];
	}

	cout << Sum << '\n';
	cout << 3;
}