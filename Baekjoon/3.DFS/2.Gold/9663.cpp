#include <iostream>
using namespace std;

int N, Cnt;
int Col[14];

bool Check(int Index)
{
	for (int i = 0; i < Index; ++i)
	{
		if (Col[i] == Col[Index]
			|| abs(Col[Index] - Col[i]) == Index - i)
		{
			return false;
		}
	}

	return true;
}

void DFS(int Index)
{
	if (Index == N)
	{
		++Cnt;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		Col[Index] = i;
		if (Check(Index))
		{
			DFS(Index + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	DFS(0);
	cout << Cnt;
}