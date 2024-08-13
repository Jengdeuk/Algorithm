#include <iostream>
#include <queue>
using namespace std;

queue<int> Q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		Q.emplace(i);
	}

	while (!Q.empty())
	{
		cout << Q.front() << ' ';
		Q.pop();
		if (Q.empty())
		{
			break;
		}

		Q.emplace(Q.front());
		Q.pop();
	}
}