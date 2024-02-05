#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> InfoTable;
vector<int> RankTable;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	InfoTable.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		int Weight, Height;
		cin >> Weight >> Height;
		InfoTable.emplace_back(Weight, Height);
	}

	RankTable.reserve(N);

	int Current = 0;
	for (const pair<int, int>& Info : InfoTable)
	{
		int CurWeight = Info.first;
		int CurHeight = Info.second;

		int Count = 0;
		int Other = 0;
		for (const pair<int, int>& OtherInfo : InfoTable)
		{
			if (Current == Other)
			{
				++Other;
				continue;
			}

			int OtherWeight = OtherInfo.first;
			int OtherHeight = OtherInfo.second;

			if (OtherWeight > CurWeight
				&& OtherHeight > CurHeight)
			{
				++Count;
			}

			++Other;
		}

		RankTable.emplace_back(Count + 1);

		++Current;
	}

	for (const int& Rank : RankTable)
	{
		cout << Rank << ' ';
	}
}