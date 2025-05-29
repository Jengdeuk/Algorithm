#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	
	int pre;
	cin >> pre;

	int up = 1, down = 1;
	int mup = up, mdown = down;
	while (--n)
	{
		int cur;
		cin >> cur;
		if (cur >= pre)
		{
			mup = max(mup, ++up);
		}
		else
		{
			up = 1;
		}

		if (cur <= pre)
		{
			mdown = max(mdown, ++down);
		}
		else
		{
			down = 1;
		}

		pre = cur;
	}

	cout << max(mup, mdown);
}