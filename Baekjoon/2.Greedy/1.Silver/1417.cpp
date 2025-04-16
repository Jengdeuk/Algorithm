#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int fnum;
	cin >> fnum;
	for (int i = 2; i <= n; ++i)
	{
		int num;
		cin >> num;
		q.emplace(num);
	}

	int cnt = 0;
	while (q.empty() == false && fnum <= q.top())
	{
		q.emplace(q.top() - 1);
		q.pop();
		fnum++;
		cnt++;
	}

	cout << cnt;
}