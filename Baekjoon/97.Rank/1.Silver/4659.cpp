#include <iostream>
#include <string>
using namespace std;

bool v[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	v['a' - 'a'] = true;
	v['e' - 'a'] = true;
	v['i' - 'a'] = true;
	v['o' - 'a'] = true;
	v['u' - 'a'] = true;

	while (true)
	{
		string s;
		cin >> s;
		if (s.compare("end") == 0)
			break;

		bool isAcceptable = true;
		bool isVow = false;
		for (int i = 0; i < s.size(); ++i)
		{
			if (isVow == false && v[s[i] - 'a'])
				isVow = true;
			
			if (i + 1 < s.size() && i + 2 < s.size()
				&& ((v[s[i] - 'a'] && v[s[i + 1] - 'a'] && v[s[i + 2] - 'a'])
					|| (v[s[i] - 'a'] == false && v[s[i + 1] - 'a'] == false && v[s[i + 2] - 'a'] == false)))
			{
				isAcceptable = false;
				break;
			}

			if (i + 1 < s.size()
				&& s[i] != 'e' && s[i] != 'o' && s[i] == s[i + 1])
			{
				isAcceptable = false;
				break;
			}
		}

		if (isVow == false)
			isAcceptable = false;

		cout << '<' << s << "> is ";
		if (isAcceptable == false)
			cout << "not ";
		cout << "acceptable.\n";
	}
}