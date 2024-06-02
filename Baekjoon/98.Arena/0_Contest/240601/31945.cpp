#include <iostream>
using namespace std;

void Test()
{
	int A, B, C, D;
	cin >> A >> B >> C >> D;

	bool Check[8] = {};
	Check[A] = true;
	Check[B] = true;
	Check[C] = true;
	Check[D] = true;

	if ((Check[0] && Check[1] && Check[2] && Check[3])
		|| (Check[0] && Check[1] && Check[4] && Check[5])
		|| (Check[0] && Check[2] && Check[4] && Check[6])
		|| (Check[1] && Check[3] && Check[5] && Check[7])
		|| (Check[2] && Check[3] && Check[6] && Check[7])
		|| (Check[4] && Check[5] && Check[6] && Check[7]))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
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