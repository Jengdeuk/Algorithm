#include <iostream>
using namespace std;

int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	int A = 1;
	for (int i = 0; i < M; ++i)
	{
		cout << 0 << ' ' << A++ << '\n';
	}
	--A;

	for (int i = A; i < N - 1; ++i)
	{
		cout << i << ' ' << i + 1 << '\n';
	}
}