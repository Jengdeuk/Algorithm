#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> PCList;
vector<bool> CheckList;

int SpreadVirus(int SourcePC)
{
	int Infected = 1;
	CheckList[SourcePC] = true;
	
	for (const int& DestinationPC : PCList[SourcePC])
	{
		if (!CheckList[DestinationPC])
		{
			Infected += SpreadVirus(DestinationPC);
		}
	}

	return Infected;
}

int main()
{
	int MaxPC;
	cin >> MaxPC;

	PCList.reserve(MaxPC);
	for (int i = 0; i < MaxPC; ++i)
	{
		PCList.emplace_back(vector<int>());
	}

	CheckList.reserve(MaxPC);
	for (int i = 0; i < MaxPC; ++i)
	{
		CheckList.emplace_back(false);
	}

	int MaxPair;
	cin >> MaxPair;
	for (int i = 0; i < MaxPair; ++i)
	{
		int SourcePC = 0, DestinationPC = 0;
		cin >> SourcePC >> DestinationPC;
		PCList[SourcePC - 1].emplace_back(DestinationPC - 1);
		PCList[DestinationPC - 1].emplace_back(SourcePC - 1);
	}

	cout << SpreadVirus(0) - 1;
}