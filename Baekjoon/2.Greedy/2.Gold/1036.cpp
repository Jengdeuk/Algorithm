#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K;
int Cnt[36][50];
int Seq[50][50];

int ConvertCharToInt(char Ch)
{
	if (Ch >= '0' && Ch <= '9')
	{
		return Ch - '0';
	}

	return Ch - 'A' + 10;
}

char ConvertIntToChar(int In)
{
	if (In < 10)
	{
		return '0' + In;
	}

	return 'A' + (In - 10);
}

void Init()
{
	memset(Seq, -1, sizeof(Seq));

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;

		int Size = S.size();
		for (int j = 0; j < Size; ++j)
		{
			int Num = ConvertCharToInt(S[j]);
			Seq[i][Size - 1 - j] = Num;
			++Cnt[Num][Size - 1 - j];
		}
	}
	cin >> K;
}

bool Compare(const int& L, const int& R)
{
	int Floor = 49;
	while (Floor >= 0)
	{
		if (Cnt[L][Floor] != Cnt[R][Floor])
		{
			return (Cnt[L][Floor] > Cnt[R][Floor]);
		}

		--Floor;
	}

	return (L < R);
}

void FindAndChangeNumber()
{
	for (int i = 0; i < 36; ++i)
	{
		int Up = 0;
		for (int j = 0; j < 49; ++j)
		{
			int Sum = (35 - i) * Cnt[i][j] + Up;
			Up = Sum / 36;
			Cnt[i][j] = Sum % 36;
		}

		Cnt[i][49] = (35 - i) * Cnt[i][49] + Up;
	}

	int NS[36] =
	{
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
		10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
		20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
		30, 31, 32, 33, 34, 35
	};

	sort(NS, NS + 36, Compare);

	bool ChangeNum[36] = {};
	for (int i = 0; i < K; ++i)
	{
		ChangeNum[NS[i]] = true;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			if (Seq[i][j] == -1)
			{
				break;
			}

			if (ChangeNum[Seq[i][j]])
			{
				Seq[i][j] = 35;
			}
		}
	}
}

string Calculate()
{
	string Answer;

	int Up = 0;
	for (int i = 0; i < 50; ++i)
	{
		int Sum = Up;
		for (int j = 0; j < N; ++j)
		{
			if (Seq[j][i] > 0)
			{
				Sum += Seq[j][i];
			}
		}

		Up = Sum / 36;
		Answer.push_back(ConvertIntToChar(Sum % 36));
	}

	while (Up > 0)
	{
		int Sum = Up;
		Up = Sum / 36;
		Answer.push_back(ConvertIntToChar(Sum % 36));
	}

	return Answer;
}

void Print(string Answer)
{
	bool bFoundFirst = false;
	for (int i = Answer.size() - 1; i >= 0; --i)
	{
		if (!bFoundFirst && Answer[i] == '0')
		{
			continue;
		}

		bFoundFirst = true;
		cout << Answer[i];
	}

	if (!bFoundFirst)
	{
		cout << '0';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Init();
	FindAndChangeNumber();
	Print(Calculate());
}