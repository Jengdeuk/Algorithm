#include <iostream>
using namespace std;

typedef pair<int, int> p;

int N;
p Ingredients[10];
bool Put[10];
int MinGap = 1234567890;

void Bruteforce(int Idx)
{
	if (Idx == N)
	{
		int S = 1, B = 0, Cnt = 0;
		for (int i = 0; i < N; ++i)
		{
			if (Put[i])
			{
				S *= Ingredients[i].first;
				B += Ingredients[i].second;
				Cnt++;
			}
		}

		if (Cnt > 0)
		{
			MinGap = min(MinGap, abs(S - B));
		}
		return;
	}

	Put[Idx] = true;
	Bruteforce(Idx + 1);
	Put[Idx] = false;
	Bruteforce(Idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Ingredients[i].first >> Ingredients[i].second;
	}

	Bruteforce(0);

	cout << MinGap;
}