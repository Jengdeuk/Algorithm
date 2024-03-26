#include <iostream>
using namespace std;

const int Button[3] = { 300, 60, 10 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;

	int Cnt[3] = {};
	for (int i = 0; i < 3; ++i)
	{
		if (T >= Button[i])
		{
			Cnt[i] = T / Button[i];
			T -= Button[i] * Cnt[i];
		}
	}

	if (T == 0)
	{
		for (int i = 0; i < 3; ++i)
		{
			cout << Cnt[i] << ' ';
		}
	}
	else
	{
		cout << -1;
	}
}