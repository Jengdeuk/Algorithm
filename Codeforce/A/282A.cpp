#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int x = 0;
	while (n--)
	{
		string s;
		cin >> s;

		bool isPlus = true;
		for (const char ch : s)
		{
			if (ch == '-')
			{
				isPlus = false;
				break;
			}
			else if (ch == '+')
			{
				break;
			}
		}

		x = (isPlus ? x + 1 : x - 1);
	}

	cout << x;
}