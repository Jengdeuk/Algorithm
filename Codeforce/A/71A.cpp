#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (s.size() <= 10)
			cout << s << '\n';
		else
			cout << s.front() << to_string(s.size() - 2) << s.back() << '\n';
	}
}