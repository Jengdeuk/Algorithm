#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> EdgeList;
vector<int> RootNode;

bool Compare(const vector<int>& Left, const vector<int>& Right)
{
	return Left[2] < Right[2];
}

int Find(const int& Node)
{
	if (Node != RootNode[Node])
	{
		RootNode[Node] = Find(RootNode[Node]);
	}

	return RootNode[Node];
}

bool Union(const int& Left, const int& Right)
{
	int RootL = Find(Left);
	int RootR = Find(Right);

	if (RootL == RootR)
	{
		return false;
	}

	int MinRoot = min(RootL, RootR);
	RootNode[RootL] = MinRoot;
	RootNode[RootR] = MinRoot;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	EdgeList.reserve(M);
	for (int i = 0; i < M; ++i)
	{
		EdgeList.emplace_back(vector<int>(3, 0));

		int Start, End, Weight;
		cin >> Start >> End >> Weight;

		EdgeList.back()[0] = Start - 1;
		EdgeList.back()[1] = End - 1;
		EdgeList.back()[2] = Weight;
	}

	sort(EdgeList.begin(), EdgeList.end(), Compare);

	RootNode.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		RootNode.emplace_back(i);
	}

	int Sum = 0;
	int Cnt = 0;
	int Current = 0;
	while (Cnt < N - 1)
	{
		int Start = EdgeList[Current][0];
		int End = EdgeList[Current][1];

		if (Union(Start, End))
		{
			Sum += EdgeList[Current][2];
			++Cnt;
		}

		++Current;
	}

	cout << Sum;
}