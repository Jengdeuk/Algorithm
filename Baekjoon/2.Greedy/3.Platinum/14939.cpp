#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int DX[5] = { 0, 0, 0, -1, 1 };
const int DY[5] = { 0, -1, 1, 0, 0 };

bool Origin[10][10];

bool StartClick[10];
bool Current[10][10];

int Min = 101;

void Click(int R, int C)
{
	for (int i = 0; i < 5; ++i)
	{
		int NR = R + DY[i];
		int NC = C + DX[i];
		if (NR < 0 || NR > 9 || NC < 0 || NC > 9)
		{
			continue;
		}

		Current[NR][NC] = !Current[NR][NC];
	}
}

bool SwitchOn()
{
	for (int j = 0; j < 10; ++j)
	{
		if (Current[9][j])
		{
			return true;
		}
	}

	return false;
}

void Counting()
{
	memcpy(Current, Origin, sizeof(Current));

	int Cnt = 0;
	for (int j = 0; j < 10; ++j)
	{
		if (StartClick[j])
		{
			++Cnt;
			Click(0, j);
		}
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (Current[i][j])
			{
				++Cnt;
				Click(i + 1, j);
			}
		}
	}

	if (SwitchOn())
	{
		return;
	}

	Min = min(Min, Cnt);
}

void DFS(int Idx)
{
	if (Idx == 10)
	{
		Counting();
		return;
	}

	StartClick[Idx] = false;
	DFS(Idx + 1);
	StartClick[Idx] = true;
	DFS(Idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 10; ++i)
	{
		string Str;
		cin >> Str;

		for (int j = 0; j < 10; ++j)
		{
			Origin[i][j] = (Str[j] == 'O') ? true : false;
		}
	}

	DFS(0);

	if (Min != 101)
	{
		cout << Min;
	}
	else
	{
		cout << -1;
	}
}