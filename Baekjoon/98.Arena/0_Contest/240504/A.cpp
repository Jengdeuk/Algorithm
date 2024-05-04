#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, X, S;
	cin >> N >> X >> S;
	for (int i = 0; i < N; ++i)
	{
		int C, P;
		cin >> C >> P;
		if (C <= X && P > S)
		{
			cout << "YES";
			exit(0);
		}
	}

	cout << "NO";
}