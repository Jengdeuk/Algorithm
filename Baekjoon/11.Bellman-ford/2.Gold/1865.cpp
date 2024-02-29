#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

const long long& Infinite = LLONG_MAX;

vector<vector<int>> EdgeList;
vector<long long> Solution;
queue<int> SearchQueue;

bool BellmanFord(int N, int K)
{
	for (int i = 0; i < N; ++i)
	{
		int EdgeSize = EdgeList.size();
		for (int j = 0; j < EdgeSize; ++j)
		{
			int Start = EdgeList[j][0];
			if (Solution[Start] != Infinite)
			{
				SearchQueue.push(j);
			}
		}

		while (!SearchQueue.empty())
		{
			int Current = SearchQueue.front();
			SearchQueue.pop();

			int Start = EdgeList[Current][0];
			int End = EdgeList[Current][1];
			int Weight = EdgeList[Current][2];

			long long NewWeight = Solution[Start] + Weight;
			if (NewWeight < Solution[End])
			{
				Solution[End] = NewWeight;
			}
		}
	}

	// Determine Infinite Cycle
	int EdgeSize = EdgeList.size();
	for (int j = 0; j < EdgeSize; ++j)
	{
		int Start = EdgeList[j][0];
		if (Solution[Start] != Infinite)
		{
			SearchQueue.push(j);
		}
	}

	while (!SearchQueue.empty())
	{
		int Current = SearchQueue.front();
		SearchQueue.pop();

		int Start = EdgeList[Current][0];
		int End = EdgeList[Current][1];
		int Weight = EdgeList[Current][2];

		long long NewWeight = Solution[Start] + Weight;
		if (NewWeight < Solution[End])
		{
			return true;
		}
	}

	return false;
}

void Test()
{
	int N, M, W;
	cin >> N >> M >> W;

	EdgeList.clear();
	EdgeList.reserve(2 * M + W);
	for (int i = 0; i < 2 * M + W; ++i)
	{
		EdgeList.emplace_back(vector<int>(3, 0));
	}

	for (int i = 0; i < M; ++i)
	{
		int Start, End, Weight;
		cin >> Start >> End >> Weight;

		EdgeList[i][0] = Start - 1;
		EdgeList[i][1] = End - 1;
		EdgeList[i][2] = Weight;

		EdgeList[M + i][0] = End - 1;
		EdgeList[M + i][1] = Start - 1;
		EdgeList[M + i][2] = Weight;
	}

	for (int i = 0; i < W; ++i)
	{
		int Start, End, Weight;
		cin >> Start >> End >> Weight;

		EdgeList[2 * M + i][0] = Start - 1;
		EdgeList[2 * M + i][1] = End - 1;
		EdgeList[2 * M + i][2] = -1 * Weight;
	}

	Solution.clear();
	Solution.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		Solution.emplace_back(0);
	}
	Solution[0] = 0;

	if (BellmanFord(N, 0))
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;
	for (int i = 0; i < TC; ++i)
	{
		Test();
	}
}