#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Sequence;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return (a.second == b.second) ? a.first < b.first : a.second > b.second;
}

int main()
{
	int N;
	cin >> N;

	Sequence.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Number;
		cin >> Number;
		Sequence.emplace_back(Number);
	}

	sort(Sequence.begin(), Sequence.end());

	vector<pair<int, int>> FrequencyMap;

	int Sum = 0;
	for (const int& Number : Sequence)
	{
		Sum += Number;

		auto iter = find_if(FrequencyMap.begin(), FrequencyMap.end(),
			[&](pair<int, int> value)
			{
				return value.first == Number;
			}
			);

		if (iter == FrequencyMap.end())
		{
			FrequencyMap.emplace_back(Number, 1);
		}
		else
		{
			++(*iter).second;
		}
	}

	sort(FrequencyMap.begin(), FrequencyMap.end(), compare);
	while (FrequencyMap.back().second != FrequencyMap.front().second)
	{
		FrequencyMap.pop_back();
	}

	int Average = round((float)Sum / Sequence.size());
	int Median = Sequence[Sequence.size() / 2];
	int Mode = (FrequencyMap.size() > 1) ? FrequencyMap[1].first : FrequencyMap[0].first;
	int Range = Sequence.back() - Sequence.front();

	cout << Average << '\n';
	cout << Median << '\n';
	cout << Mode << '\n';
	cout << Range << '\n';
}