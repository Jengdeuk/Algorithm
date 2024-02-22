#include <iostream>
#include <algorithm>
using namespace std;

int Sum[100000];

void Init(int N)
{
	int Num;
	cin >> Num;
	Sum[1] = Num;
	for (int i = 2; i <= N; ++i)
	{
		cin >> Num;
		Sum[i] = Sum[i - 1] + Num;
	}
}

int GetLength(int N, int S)
{
	int Min = 100000;

	int Left = 1;
	int Right = 1;
	while (Left <= Right)
	{
		int SubSum = Sum[Right] - Sum[Left - 1];

		if (SubSum >= S)
		{
			int Length = Right - Left + 1;
			if (Length < Min)
			{
				Min = Length;
			}

			++Left;
		}
		else
		{
			++Right;
			if (Right > N)
			{
				break;
			}
		}
	}

	if (Min == 100000)
	{
		return 0;
	}

	return Min;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, S;
	cin >> N >> S;

	Init(N);

	cout << GetLength(N, S);
}