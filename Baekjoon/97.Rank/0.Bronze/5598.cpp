#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		char ch = s[i] - 3;
		if (ch < 65)
			ch += 26;
		cout << ch;
	}
}