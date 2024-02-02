#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

const long long& Infinite = LLONG_MAX;

vector<vector<int>> EdgeList;
vector<long long> Solution;
queue<int> SearchQueue;

bool BellmanFord(int N, int M, int K)
{
	Solution.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		Solution.emplace_back(Infinite);
	}
	Solution[K] = 0;

	// Update Solution
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int Start = EdgeList[j][0];
			if (Solution[Start] != Infinite)
			{
				SearchQueue.emplace(j);
			}
		}

		while (!SearchQueue.empty())
		{
			int CurrentEdge = SearchQueue.front();
			SearchQueue.pop();

			int Start = EdgeList[CurrentEdge][0];
			int End = EdgeList[CurrentEdge][1];
			int Weight = EdgeList[CurrentEdge][2];

			long long NewWeight = Solution[Start] + Weight;
			if (NewWeight < Solution[End])
			{
				Solution[End] = NewWeight;
			}
		}
	}

	// Determine Infinite Cycle
	for (int j = 0; j < M; ++j)
	{
		int Start = EdgeList[j][0];
		if (Solution[Start] != Infinite)
		{
			SearchQueue.emplace(j);
		}
	}

	while (!SearchQueue.empty())
	{
		int CurrentEdge = SearchQueue.front();
		SearchQueue.pop();

		int Start = EdgeList[CurrentEdge][0];
		int End = EdgeList[CurrentEdge][1];
		int Weight = EdgeList[CurrentEdge][2];

		long long NewWeight = Solution[Start] + Weight;
		if (NewWeight < Solution[End])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		EdgeList.emplace_back(vector<int>());
		EdgeList.back().reserve(3);

		int Start, End, Weight;
		cin >> Start >> End >> Weight;

		EdgeList.back().emplace_back(Start - 1);
		EdgeList.back().emplace_back(End - 1);
		EdgeList.back().emplace_back(Weight);
	}

	if (!BellmanFord(N, M, 0))
	{
		cout << -1;
		return 0;
	}

	for (int i = 1; i < N; ++i)
	{
		if (Solution[i] == Infinite)
		{
			cout << -1 << '\n';
			continue;
		}

		cout << Solution[i] << '\n';
	}
}