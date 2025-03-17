#include <iostream>
#include <string>
#include <stack>
using namespace std;

void test()
{
	string s;
	cin >> s;
	
	stack<char> stl, str;
	for (int i = 0; i < s.size(); ++i)
	{
		char ch = s[i];
		switch (ch)
		{
		case '<':
			if (stl.empty() == false)
			{
				str.emplace(stl.top());
				stl.pop();
			}
			break;
		case '>':
			if (str.empty() == false)
			{
				stl.emplace(str.top());
				str.pop();
			}
			break;
		case '-':
			if (stl.empty() == false)
				stl.pop();
			break;
		default:
			stl.emplace(ch);
			break;
		}
	}

	while (str.empty() == false)
	{
		stl.emplace(str.top());
		str.pop();
	}

	while (stl.empty() == false)
	{
		str.emplace(stl.top());
		stl.pop();
	}

	while (str.empty() == false)
	{
		cout << str.top();
		str.pop();
	}

	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) test();
}