#include <iostream>
#include <algorithm>
using namespace std;

int N, Q;
int H[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int S;
		cin >> S;
		H[i] = max(S + i - 1, H[i - 1]);
	}

	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		int S;
		cin >> S;
		cout << (lower_bound(H + 1, H + N + 1, S) - H) << ' ';
	}
}