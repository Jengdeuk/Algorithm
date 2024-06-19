#include <iostream>
#include <string>
using namespace std;

void Test(int T)
{
	int Max;
	cin >> Max;

	string Str;
	cin >> Str;

	int H = 0, R = 0;
	for (int i = 0; i <= Max; ++i)
	{
		int Num = Str[i] - '0';
		if (H >= i)
		{
			H += Num;
		}
		else
		{
			R += abs(H - i);
			H += abs(H - i) + Num;
		}
	}

	cout << "Case #" << T << ": " << R << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		Test(i);
	}
}