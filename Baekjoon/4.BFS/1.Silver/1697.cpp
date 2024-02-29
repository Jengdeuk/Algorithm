#include <iostream>
#include <queue>
using namespace std;

const int& MaxSize = 100000;

int Map[MaxSize + 1];
queue<int> SearchQueue;

bool IsInSize(int Node)
{
	return (Node >= 0 && Node <= MaxSize);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	SearchQueue.emplace(N);
	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.front();
		SearchQueue.pop();

		int Neighbors[3] =
		{
			Current - 1,
			Current + 1,
			2 * Current
		};

		for (int i = 0; i < 3; ++i)
		{
			if (IsInSize(Neighbors[i])
				&& Map[Neighbors[i]] == 0)
			{
				Map[Neighbors[i]] = Map[Current] + 1;
				SearchQueue.emplace(Neighbors[i]);
			}
		}
	}

	if (N == K)
	{
		cout << 0;
	}
	else
	{
		cout << Map[K];
	}
}