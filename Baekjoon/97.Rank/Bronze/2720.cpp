#include <iostream>
using namespace std;

const int QDNP[4] = { 25, 10, 5, 1 };

void Test()
{
	int C;
	cin >> C;

	for (int i = 0; i < 4; ++i)
	{
		int Cnt = 0;
		if (C >= QDNP[i])
		{
			Cnt += C / QDNP[i];
			C -= QDNP[i] * (C / QDNP[i]);
		}

		cout << Cnt << ' ';
	}
	cout << '\n';
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