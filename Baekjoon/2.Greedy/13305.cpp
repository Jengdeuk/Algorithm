#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long>> City;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	City.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		int Distance = 0;
		if (i < N - 1)
		{
			cin >> Distance;
		}
		City.emplace_back(0, Distance);
	}

	for (pair<long long, long long>& Info : City)
	{
		long long Cost;
		cin >> Cost;
		Info.first = Cost;
	}

	long long Cost = 0;
	int NextStation = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		if (i != NextStation)
		{
			continue;
		}

		long long CurCost = City[i].first;

		NextStation = i + 1;
		while (CurCost < City[NextStation].first)
		{
			++NextStation;
		}

		for (int j = i; j < NextStation; ++j)
		{
			Cost += CurCost * City[j].second;
		}
	}

	cout << Cost;
}