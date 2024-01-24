#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Cards;
vector<int> Solutions;

int main()
{
	int N, M;
	cin >> N >> M;

	Cards.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Card;
		cin >> Card;
		Cards.emplace_back(Card);
	}

	sort(Cards.begin(), Cards.end(), greater<>());

	for (int First = 0; First < N - 2; ++First)
	{
		for (int Second = First + 1; Second < N - 1; ++Second)
		{
			for (int Third = Second + 1; Third < N; ++Third)
			{
				int Sum = Cards[First] + Cards[Second] + Cards[Third];
				if (Sum > M)
				{
					continue;
				}
				else
				{
					Solutions.emplace_back(Sum);
				}
			}
		}
	}

	sort(Solutions.begin(), Solutions.end(), greater<>());
	cout << Solutions.front();
}