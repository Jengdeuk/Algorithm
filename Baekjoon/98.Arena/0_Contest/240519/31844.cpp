#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	int R = 0, B = 0, G = 0;
	for (int i = 0; i < S.size(); ++i)
	{
		if (S[i] == '@')
		{
			R = i;
		}
		else if (S[i] == '#')
		{
			B = i;
		}
		else if (S[i] == '!')
		{
			G = i;
		}
	}

	bool bClear = false;
	if (R < G)
	{
		if (B > R && B < G)
		{
			bClear = true;
		}
	}
	else
	{
		if (B > G && B < R)
		{
			bClear = true;
		}
	}

	if (bClear)
	{
		cout << abs(G - R) - 1;
	}
	else
	{
		cout << -1;
	}
}