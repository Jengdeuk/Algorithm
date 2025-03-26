#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;
	priority_queue<ll, vector<ll>, greater<ll>> q;

	cin >> n >> m;
	while (n--)
	{
		ll num;
		cin >> num;
		q.emplace(num);
	}

	while (m--)
	{
		ll sum = 0;
		for (int i = 0; i < 2; ++i)
		{
			sum += q.top();
			q.pop();
		}

		for (int i = 0; i < 2; ++i)
			q.emplace(sum);
	}

	ll answer = 0;
	while (q.empty() == false)
	{
		answer += q.top();
		q.pop();
	}

	cout << answer;
}