#include <iostream>
#include <queue>
using namespace std;

queue<int> Cards;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		Cards.emplace(i);
	}

	int Card = 0;
	bool bDrop = true;
	while (!Cards.empty())
	{
		Card = Cards.front();
		Cards.pop();

		if (bDrop)
		{
			bDrop = false;
			continue;
		}

		bDrop = true;
		Cards.emplace(Card);
	}
	cout << Card;
}