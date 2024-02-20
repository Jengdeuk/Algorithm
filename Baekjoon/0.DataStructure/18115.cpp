#include <iostream>
#include <deque>
using namespace std;

deque<int> Skills;
deque<int> InitialCards;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int Skill;
		cin >> Skill;
		Skills.push_back(Skill);
	}

	for (int Card = 1; Card <= N; ++Card)
	{
		int Skill = Skills.back();
		Skills.pop_back();

		int Temp;
		switch (Skill)
		{
		case 1:
			InitialCards.push_front(Card);
			break;

		case 2:
			InitialCards.push_front(Card);
			Temp = InitialCards[0];
			InitialCards[0] = InitialCards[1];
			InitialCards[1] = Temp;
			break;

		case 3:
			InitialCards.push_back(Card);
			break;
		}
	}

	while (!InitialCards.empty())
	{
		cout << InitialCards.front() << ' ';
		InitialCards.pop_front();
	}
}