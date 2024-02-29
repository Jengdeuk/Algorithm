#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> OrderedList;

void Test()
{
	int N;
	cin >> N;

	OrderedList.reserve(N);
	OrderedList.clear();
	pair<int, int> Ranks;
	for (int i = 0; i < N; ++i)
	{
		cin >> Ranks.first >> Ranks.second;
		OrderedList.emplace_back(Ranks);
	}

	sort(OrderedList.begin(), OrderedList.end());

	int Count = 0;
	int MinRank = OrderedList.front().second;
	for (int i = 1; i < N; ++i)
	{
		int CurrentRank = OrderedList[i].second;

		if (CurrentRank < MinRank)
		{
			MinRank = CurrentRank;
		}
		else
		{
			++Count;
		}
	}

	cout << N - Count << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}