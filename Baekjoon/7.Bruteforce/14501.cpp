#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> Schedule;
vector<bool> Solution;
vector<int> Solutions;

void DFS(int N, int Current, int Working, vector<bool> Solution)
{
	if (Working > 0)
	{
		--Working;
	}

	if (Current == N - 1)
	{
		if (Working == 0
			&& Schedule[Current].first <= N - Current)
		{
			Solution[Current] = true;
		}

		int Price = 0;
		int Index = 0;
		for (const bool& Work : Solution)
		{
			if (Work)
			{
				Price += Schedule[Index].second;
			}

			++Index;
		}

		Solutions.emplace_back(Price);

		return;
	}

	Solution[Current] = false;
	DFS(N, Current + 1, Working, Solution);

	if ((Working == 0)
		&& Schedule[Current].first <= N - Current)
	{
		Solution[Current] = true;
		Working = Schedule[Current].first;
		DFS(N, Current + 1, Working, Solution);
	}
}

int main()
{
	int N;
	cin >> N;

	Schedule.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int T, P;
		cin >> T >> P;
		Schedule.emplace_back(T, P);
	}

	Solution.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		Solution.emplace_back(false);
	}

	DFS(N, 0, 0, Solution);

	cout << *max_element(Solutions.begin(), Solutions.end());
}