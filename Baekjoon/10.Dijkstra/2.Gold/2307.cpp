#include <iostream>
#include <list>
using namespace std;

typedef pair<int, int> p;

int n;
list<p> f[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	int m;
	cin >> m;
	while (m--)
	{
		int a, b, t;
		cin >> a >> b >> t;
		f[a].emplace_back(b, t);
		f[b].emplace_back(a, t);
	}
}