#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string s;
	cin >> s;

	int cnt = 1;
	for (int i = 0; i < s.size(); ++i)
	{
		switch (s[i])
		{
		case 'c':
			if (i > 0 && s[i - 1] == 'c')
				cnt *= 25;
			else
				cnt *= 26;
			break;
		case 'd':
			if (i > 0 && s[i - 1] == 'd')
				cnt *= 9;
			else
				cnt *= 10;
			break;
		}
	}

	cout << cnt;
}