#include <iostream>
#include <queue>
using namespace std;

int n;
bool isStack[100000];
int qs[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> isStack[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> qs[i];
	}

	queue<int> q;
	for (int i = n - 1; i >= 0; --i)
	{
		if (isStack[i] == false)
		{
			q.emplace(qs[i]);
		}
	}

	int m;
	cin >> m;
	while (m--)
	{
		int num;
		cin >> num;
		q.emplace(num);

		cout << q.front() << ' ';
		q.pop();
	}
}