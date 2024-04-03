#include <iostream>
using namespace std;

int N;
int Seq[8];

int Sol[8];
bool Check[8];
int Max = -99999999;

void Backtracking(int Idx)
{
	if (Idx == N)
	{
		int Sum = 0;
		for (int i = 0; i + 1 < N; ++i)
		{
			Sum += abs(Sol[i] - Sol[i + 1]);
		}
		Max = max(Max, Sum);
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (Check[i])
		{
			continue;
		}

		Check[i] = true;
		Sol[Idx] = Seq[i];
		Backtracking(Idx + 1);
		Check[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Seq[i];
	}

	Backtracking(0);
	cout << Max;
}