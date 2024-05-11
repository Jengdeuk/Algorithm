#include <iostream>
using namespace std;

void Test()
{
	int N, S, E;
	cin >> N >> S >> E;

	if ((S == 1 || S == N) && (E == 1 || E == N))
	{
		cout << 0 << '\n';
	}
	else if (S == 1 || S == N || abs(S - E) == 1)
	{
		cout << 1 << '\n';
	}
	else
	{
		cout << 2 << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}