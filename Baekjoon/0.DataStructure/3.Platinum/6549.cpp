#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int n;
stack<p> s;

bool Test()
{
	cin >> n;
	if (n == 0)
	{
		return false;
	}

	ll me = 0;
	for (int i = 0; i < n; ++i)
	{
		int h;
		cin >> h;

		while (s.empty() == false && s.top().first > h)
		{
			ll curH = s.top().first;
			ll curW = i;
			s.pop();

			if (s.empty() == false)
			{
				curW = i - s.top().second - 1;
			}

			me = max(me, curH * curW);
		}

		s.push(p(h, i));
	}

	while (s.empty() == false)
	{
		ll curH = s.top().first;
		ll curW = n;
		s.pop();

		if (s.empty() == false)
		{
			curW = n - s.top().second - 1;
		}

		me = max(me, curH * curW);
	}

	cout << me << '\n';

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		if (Test() == false)
		{
			break;
		}
	}
}