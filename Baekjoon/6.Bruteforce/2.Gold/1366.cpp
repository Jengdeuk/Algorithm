#include <iostream>
#include <string>
using namespace std;

int N, M;
int Code[6], Scale[6], Sol[6];
int Min = 987654321;

bool Check();
int Count();

void DFS(int Idx);
void InputScale(string S, int Index);
void InputCode(string S, int Index);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		InputScale(S, i);
	}

	for (int i = 0; i < M; ++i)
	{
		string S;
		cin >> S;
		InputCode(S, i);
	}

	DFS(0);

	cout << Min;
}

void DFS(int Idx)
{
	if (Idx == N)
	{
		if (Check())
		{
			Min = min(Min, Count());
		}

		return;
	}

	for (int i = 0; i < M; ++i)
	{
		Sol[Idx] = Code[i];
		DFS(Idx + 1);
		Sol[Idx] = Code[i] + 12;
		DFS(Idx + 1);
	}
}

int Count()
{
	int MinFret = 987654321;
	int MaxFret = 0;

	for (int i = 0; i < N; ++i)
	{
		int Fret;
		if (Sol[i] == Scale[i])
		{
			Fret = 0;
		}
		else if (Sol[i] > Scale[i])
		{
			Fret = Sol[i] - Scale[i];
		}
		else
		{
			Fret = 12 - (Scale[i] - Sol[i]);
		}

		if (Fret != 0)
		{
			MinFret = min(MinFret, Fret);
			MaxFret = max(MaxFret, Fret);
		}
	}

	if (MaxFret == 0)
	{
		return 0;
	}

	return MaxFret - MinFret + 1;
}

bool Check()
{
	bool Sound[6] = {};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Sol[i] % 13 == Code[j])
			{
				Sound[j] = true;
				break;
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		if (!Sound[i])
		{
			return false;
		}
	}

	return true;
}

void InputScale(string S, int Index)
{
	switch (S[0])
	{
	case 'A':
		if (S.size() == 1)
		{
			Scale[Index] = 1;
		}
		else
		{
			Scale[Index] = 2;
		}
		break;
	case 'B':
		Scale[Index] = 3;
		break;
	case 'C':
		if (S.size() == 1)
		{
			Scale[Index] = 4;
		}
		else
		{
			Scale[Index] = 5;
		}
		break;
	case 'D':
		if (S.size() == 1)
		{
			Scale[Index] = 6;
		}
		else
		{
			Scale[Index] = 7;
		}
		break;
	case 'E':
		Scale[Index] = 8;
		break;
	case 'F':
		if (S.size() == 1)
		{
			Scale[Index] = 9;
		}
		else
		{
			Scale[Index] = 10;
		}
		break;
	case 'G':
		if (S.size() == 1)
		{
			Scale[Index] = 11;
		}
		else
		{
			Scale[Index] = 12;
		}
		break;
	}
}

void InputCode(string S, int Index)
{
	switch (S[0])
	{
	case 'A':
		if (S.size() == 1)
		{
			Code[Index] = 1;
		}
		else
		{
			Code[Index] = 2;
		}
		break;
	case 'B':
		Code[Index] = 3;
		break;
	case 'C':
		if (S.size() == 1)
		{
			Code[Index] = 4;
		}
		else
		{
			Code[Index] = 5;
		}
		break;
	case 'D':
		if (S.size() == 1)
		{
			Code[Index] = 6;
		}
		else
		{
			Code[Index] = 7;
		}
		break;
	case 'E':
		Code[Index] = 8;
		break;
	case 'F':
		if (S.size() == 1)
		{
			Code[Index] = 9;
		}
		else
		{
			Code[Index] = 10;
		}
		break;
	case 'G':
		if (S.size() == 1)
		{
			Code[Index] = 11;
		}
		else
		{
			Code[Index] = 12;
		}
		break;
	}
}