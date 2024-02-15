#include <iostream>
using namespace std;

long long P[101] = { 0, 1, 1, 1, 2, 2, };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 6; i <= 100; ++i)
	{
		P[i] = P[i - 5] + P[i - 1];
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		cout << P[N] << '\n';
	}
}