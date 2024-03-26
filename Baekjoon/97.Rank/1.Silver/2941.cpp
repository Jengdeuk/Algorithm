#include <iostream>
#include <string>
using namespace std;

int CountNum(const string& str)
{
	int i = 0, Cnt = 0;
	while (i < str.size())
	{
		++Cnt;

		switch (str[i])
		{
		case 'c':
			if (i < str.size() - 1
				&& (str[i + 1] == '=' || str[i + 1] == '-'))
			{
				i += 2;
			}
			else
			{
				++i;
			}
			break;

		case 'd':
			if (i < str.size() - 2
				&& (str[i + 1] == 'z' && str[i + 2] == '='))
			{
				i += 3;
			}
			else if (i < str.size() - 1
				&& (str[i + 1] == '-'))
			{
				i += 2;
			}
			else
			{
				++i;
			}
			break;

		case 'l':
		case 'n':
			if (i < str.size() - 1
				&& (str[i + 1] == 'j'))
			{
				i += 2;
			}
			else
			{
				++i;
			}
			break;

		case 's':
		case 'z':
			if (i < str.size() - 1
				&& (str[i + 1] == '='))
			{
				i += 2;
			}
			else
			{
				++i;
			}
			break;

		default:
			++i;
			break;
		}
	}

	return Cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string str;
	cin >> str;
	cout << CountNum(str);
}