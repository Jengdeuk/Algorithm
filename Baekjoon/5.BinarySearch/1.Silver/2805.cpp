#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> Trees;
	Trees.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Tree;
		cin >> Tree;
		Trees.emplace_back(Tree);
	}

	int Result = 0;
	int Height = 0;
	int MinHeight = 0;
	int MaxHeight = *max_element(Trees.begin(), Trees.end());
	while (MinHeight <= MaxHeight)
	{
		Height = (MinHeight + MaxHeight) / 2;

		long long Sum = 0;
		for (const int& Tree : Trees)
		{
			if (Tree > Height)
			{
				Sum += Tree - Height;
			}
		}

		if (Sum < M)
		{
			MaxHeight = Height - 1;
		}
		else
		{
			Result = Height;
			MinHeight = Height + 1;
		}
	}

	cout << Result;
}