#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meet
{
	int Start;
	int End;

	Meet(int StartTime, int EndTime) : Start(StartTime), End(EndTime) {}

	bool operator<(const Meet& rhs) const
	{
		return (End != rhs.End) ? End < rhs.End : Start < rhs.Start;
	}
};

vector<Meet> Meets;

int main()
{
	int n;
	cin >> n;
	Meets.reserve(n);

	for (int i = 0; i < n; ++i)
	{
		int Start = 0, End = 0;
		cin >> Start >> End;
		Meets.emplace_back(Meet(Start, End));
	}

	sort(Meets.begin(), Meets.end(), less<>());

	int Count = 1;
	int PrevEndTime = Meets.front().End;
	for (int i = 1; i < n; ++i)
	{
		if (PrevEndTime <= Meets[i].Start)
		{
			PrevEndTime = Meets[i].End;
			++Count;
		}
	}

	cout << Count;
}