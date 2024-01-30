#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	vector<int> Dices;
	Dices.reserve(3);

	Dices.emplace_back(A);
	Dices.emplace_back(B);
	Dices.emplace_back(C);

	sort(Dices.begin(), Dices.end(), greater<>());

	int Reward = 0;
	if (Dices[0] == Dices[1]
		&& Dices[1] == Dices[2]
		&& Dices[2] == Dices[0])
	{
		Reward = 10000 + Dices.front() * 1000;
	}
	else if (Dices[0] == Dices[1])
	{
		Reward = 1000 + Dices[0] * 100;
	}
	else if (Dices[1] == Dices[2])
	{
		Reward = 1000 + Dices[1] * 100;
	}
	else if (Dices[2] == Dices[1])
	{
		Reward = 1000 + Dices[2] * 100;
	}
	else
	{
		Reward = Dices.front() * 100;
	}

	cout << Reward;
}