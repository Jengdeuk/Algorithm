#include <iostream>
using namespace std;

int s[2][9];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int j = 0; j < 2; ++j)
		for (int i = 0; i < 9; ++i)
			cin >> s[j][i];

	bool isReversed = false;
	int a = 0, b = 0;
	for (int i = 0; i < 9; ++i)
	{
		a += s[0][i];
		if (a > b)
			isReversed = true;
		b += s[1][i];
	}

	cout << (isReversed ? "Yes" : "No");
}