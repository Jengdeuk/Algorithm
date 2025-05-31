#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int k;
	cin >> k;

	int l[6];
	for (int i = 0; i < 6; ++i)
	{
		int num;
		cin >> num >> l[i];
	}

	bool c[6] = {};

	int a = max(l[0], max(l[2], l[4]));
	for (int i = 0; i < 6; i += 2)
	{
		if (l[i] == a)
		{
			c[i] = true;
			break;
		}
	}

	int b = max(l[1], max(l[3], l[5]));
	for (int i = 1; i < 6; i += 2)
	{
		if (l[i] == b)
		{
			c[i] = true;
			break;
		}
	}

	int big = a * b;

	for (int i = 0; i < 6; ++i)
	{
		if (i == 5)
		{
			c[1] = true;
			c[4] = true;
			break;
		}
		
		if (c[i] && c[i + 1])
		{
			c[(i - 1 < 0 ? 5 : i - 1)] = true;
			c[(i + 2 > 5 ? 0 : i + 2)] = true;
			break;
		}
	}

	int small = 1;
	for (int i = 0; i < 6; ++i)
	{
		if (c[i] == false)
		{
			small *= l[i];
		}
	}

	cout << k * (big - small);
}