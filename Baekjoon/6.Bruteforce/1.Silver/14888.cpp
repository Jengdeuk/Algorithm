#include <iostream>
using namespace std;

int N;
int Sequence[11];
int Operator[10];
int Inventory[4];

int Max = -1000000000;
int Min = 1000000000;

void Calculate()
{
	int Result = Sequence[0];
	for (int i = 0; i < N - 1; ++i)
	{
		switch (Operator[i])
		{
		case 0:
			Result = Result + Sequence[i + 1];
			break;

		case 1:
			Result = Result - Sequence[i + 1];
			break;

		case 2:
			Result = Result * Sequence[i + 1];
			break;

		case 3:
			Result = Result / Sequence[i + 1];
			break;
		}
	}

	if (Result > Max)
	{
		Max = Result;
	}

	if (Result < Min)
	{
		Min = Result;
	}
}

void Backtracking(int Index)
{
	if (Index == N - 1)
	{
		Calculate();
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (Inventory[i] == 0)
		{
			continue;
		}

		--Inventory[i];
		Operator[Index] = i;
		Backtracking(Index + 1);
		++Inventory[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Sequence[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		cin >> Inventory[i];
	}

	Backtracking(0);

	cout << Max << '\n';
	cout << Min;
}