#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string a, b;
	cin >> a >> b;

	string s;
	for (int i = 0; i < a.size(); ++i)
	{
		s.push_back(a[i]);
		s.push_back(b[i]);
	}

	while (s.size() > 2)
	{
		string temp;
		for (int i = 0; i < s.size() - 1; ++i)
			temp.push_back((s[i] - '0' + s[i + 1] - '0') % 10 + '0');

		s = temp;
	}
	
	cout << s;
}