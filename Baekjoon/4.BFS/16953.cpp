#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<pair<int, int>> SearchQueue;

int BFS(int Start, int End)
{
	SearchQueue.emplace(Start, 1);
	while (!SearchQueue.empty())
	{
		long long Current = SearchQueue.front().first;
		int Depth = SearchQueue.front().second;
		SearchQueue.pop();

		if (Current == End)
		{
			return Depth;
		}
		else if (Current > End)
		{
			continue;
		}

		long long N1 = 2 * Current;
		if (N1 <= 1000000000)
		{
			SearchQueue.emplace(N1, Depth + 1);
		}

		long long N2 = Current * 10 + 1;
		if (N2 <= 1000000000)
		{
			SearchQueue.emplace(N2, Depth + 1);
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	cout << BFS(A, B);
}