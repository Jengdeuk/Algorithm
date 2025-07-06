#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;

int N;
ip NumList[1000];
unordered_map<int, int> Count, Order;

bool Compare(const ip& L, const ip& R)
{
	return (L.second.first == R.second.first ? L.second.second < R.second.second : L.second.first > R.second.first);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int C;
	cin >> N >> C;
	for (int i = 1; i <= N; ++i)
	{
		int Num;
		cin >> Num;
		if (Count.count(Num) == 0)
		{
			Order[Num] = i;
		}
		Count[Num]++;
	}

	int Idx = 0;
	for (const p Elem : Count)
	{
		int Num = Elem.first;
		NumList[Idx++] = ip(Num, p(Elem.second, Order[Num]));
	}

	sort(NumList, NumList + Idx, Compare);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < NumList[i].second.first; ++j)
		{
			cout << NumList[i].first << ' ';
		}
	}
}