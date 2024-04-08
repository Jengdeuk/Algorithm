#include <iostream>
#include <unordered_map>
using namespace std;

int N, S;
int Seq[40];
unordered_map<int, int> Left;
bool Select[40];

long long Cnt;

void LB(int Idx, int Size)
{
	if (Idx == Size)
	{
		int Sum = 0;
		for (int i = 0; i < Size; ++i)
		{
			if (Select[i])
			{
				Sum += Seq[i];
			}
		}
		++Left[Sum];

		return;
	}

	Select[Idx] = true;
	LB(Idx + 1, Size);
	Select[Idx] = false;
	LB(Idx + 1, Size);
}

void RB(int Idx, int Size)
{
	if (Idx == Size)
	{
		int Sum = 0;
		for (int i = Size / 2; i < Size; ++i)
		{
			if (Select[i])
			{
				Sum += Seq[i];
			}
		}
		Cnt += Left[S - Sum];

		return;
	}

	Select[Idx] = true;
	RB(Idx + 1, Size);
	Select[Idx] = false;
	RB(Idx + 1, Size);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> S;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> Seq[i];
	}

	LB(0, N / 2);
	RB(N / 2, N);

	if (S != 0)
	{
		cout << Cnt;
	}
	else
	{
		cout << Cnt - 1;
	}
}