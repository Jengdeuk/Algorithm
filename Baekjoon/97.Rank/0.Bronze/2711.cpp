#include <iostream>
#include <string>
using namespace std;

void test()
{
	int idx;
	cin >> idx;
	idx--;

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i)
		if (i != idx)
			cout << s[i];

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