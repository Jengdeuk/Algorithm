#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> Cards;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Card;
		cin >> Card;
		Cards.emplace(Card);
	}

	int Cnt = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		int First = Cards.top();
		Cards.pop();

		int Second = Cards.top();
		Cards.pop();

		int NewCard = First + Second;
		Cards.emplace(NewCard);

		Cnt += NewCard;
	}

	cout << Cnt;
}