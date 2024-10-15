#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, int> pi;

int N, C;
pi Info[10000];
int Truck[2001];

bool Compare(const pi& L, const pi& R)
{
	return (L.first.second == R.first.second ? L.first.first < R.first.first : L.first.second < R.first.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> C;
	
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> Info[i].first.first >> Info[i].first.second >> Info[i].second;
	}

	sort(Info, Info + M, Compare);

	int Total = 0;
	for (int i = 0; i < M; ++i)
	{
		int Src = Info[i].first.first;
		int Dst = Info[i].first.second;
		int Box = Info[i].second;

		int Max = 0;
		for (int j = Src; j < Dst; ++j)
		{
			Max = max(Max, Truck[j]);
		}

		int Blank = min(Box, C - Max);
		for (int j = Src; j < Dst; ++j)
		{
			Truck[j] += Blank;
		}

		Total += Blank;
	}
	
	cout << Total;
}