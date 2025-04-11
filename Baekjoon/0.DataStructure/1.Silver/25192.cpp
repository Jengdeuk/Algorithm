#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<string> us;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int cnt = 0;
	while (n--)
	{
		string s;
		cin >> s;
		if (s.compare("ENTER") == 0)
		{
			cnt += us.size();
			unordered_set<string>().swap(us);
			continue;
		}

		us.emplace(s);
	}

	cnt += us.size();
	cout << cnt;
}