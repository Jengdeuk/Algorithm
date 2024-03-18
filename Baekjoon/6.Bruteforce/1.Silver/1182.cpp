#include <iostream>
using namespace std;

int N, S;
int Sequence[20];
bool Select[20];
int Cnt;

bool Check()
{
	bool bSelect = false;
	for (int i = 0; i < N; ++i)
	{
		if (Select[i])
		{
			bSelect = true;
			break;
		}
	}

	if (!bSelect)
	{
		return false;
	}

	int Sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (Select[i])
		{
			Sum += Sequence[i];
		}
	}

	if (Sum == S)
	{
		return true;
	}
	
	return false;
}

void Backtracking(int Idx)
{
	if (Idx == N)
	{
		if (Check())
		{
			++Cnt;
		}

		return;
	}

	Select[Idx] = true;
	Backtracking(Idx + 1);
	Select[Idx] = false;
	Backtracking(Idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> S;

	for (int i = 0; i < N; ++i)
	{
		cin >> Sequence[i];
	}

	Backtracking(0);

	cout << Cnt;
}