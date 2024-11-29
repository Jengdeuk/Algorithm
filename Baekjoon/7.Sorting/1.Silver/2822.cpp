#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

bool Take[8];
p Score[8];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 8; ++i)
	{
		cin >> Score[i].first;
		Score[i].second = i;
	}

	sort(Score, Score + 8, greater<>());

	int Sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		Sum += Score[i].first;
		Take[Score[i].second] = true;
	}

	cout << Sum << '\n';
	for (int i = 0; i < 8; ++i)
	{
		if (Take[i])
		{
			cout << i + 1 << ' ';
		}
	}
}