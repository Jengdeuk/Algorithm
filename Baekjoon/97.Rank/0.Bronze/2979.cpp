#include <iostream>
using namespace std;

int t[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	for (int i = 0; i < 3; ++i)
	{
		int s, e;
		cin >> s >> e;
		for (int j = s; j < e; ++j)
			t[j]++;
	}

	int cst = 0;
	for (int i = 1; i <= 100; ++i)
	{
		int add = 0;
		switch (t[i])
		{
		case 1:
			add = a;
			break;
		case 2:
			add = b * 2;
			break;
		case 3:
			add = c * 3;
			break;
		}
		cst += add;
	}

	cout << cst;
}