#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string s;
	cin >> s;

	int mn = 0;
	for (int k = 0; k < s.size(); ++k)
	{
		int n = 0;
		int i = k;
		for (int j = k + 1; j < s.size(); ++j)
		{
			if (s[i] == s[j])
			{
				mn = max(mn, ++n);
				i++;
				continue;
			}

			n = 0;
			i = k;
			if (s[i] == s[j])
			{
				mn = max(mn, ++n);
				i++;
			}
		}
	}
	
	cout << mn;
}