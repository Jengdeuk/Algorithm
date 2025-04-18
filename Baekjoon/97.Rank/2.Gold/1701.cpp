#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getP(string s)
{
	vector<int> p(s.size(), 0);

	int j = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		while (j > 0 && s[i] != s[j])
		{
			j = p[j - 1];
		}

		if (s[i] == s[j])
			p[i] = ++j;
	}

	return p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string s;
	cin >> s;
	
	int m = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		vector p(getP(s.substr(i, s.size() - i)));
		for (int j = 0; j < s.size() - i; ++j)
		{
			m = max(m, p[j]);
		}
	}

	cout << m;
}