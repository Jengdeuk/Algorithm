#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	while (n--)
	{
		string a, b;
		cin >> a >> b;
		if (a.compare("ChongChong") == 0 || b.compare("ChongChong") == 0 || m[a] || m[b])
		{
			m[a] = true;
			m[b] = true;
		}
	}

	int cnt = 0;
	for (auto p : m)
		if (p.second)
			cnt++;

	cout << cnt;
}