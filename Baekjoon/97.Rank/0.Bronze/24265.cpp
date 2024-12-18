#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	long long Cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		Cnt += N - i;
	}

	cout << Cnt << '\n';
	cout << 2;
}