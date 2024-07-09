#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N;
p L[1000000];

bool Compare(const p& Left, const p& Right)
{
	return (Left.first == Right.first ? Left.second < Right.second : Left.first < Right.first);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> L[i].first >> L[i].second;
	}

	sort(L, L + N, Compare);

	int Sum = 0, Point = -1000000000;
	for (int i = 0; i < N; ++i)
	{
		int Left = L[i].first;
		int Right = L[i].second;
		if (Point < Left)
		{
			Point = Left;
		}

		if (Point < Right)
		{
			Sum += Right - Point;
			Point = Right;
		}
	}

	cout << Sum;
}